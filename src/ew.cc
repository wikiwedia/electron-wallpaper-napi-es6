/*
 * Copyright 2018 Robin Andersson <me@robinwassen.com>
 * Copyright 2019 Zisu Zhang <admin@zhangzisu.cn>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ew.h"

BOOL CALLBACK ew::FindWorkerW(HWND hwnd, LPARAM param) {
	HWND shelldll = FindWindowEx(hwnd, NULL, L"SHELLDLL_DefView", NULL);

	if (shelldll) {
		workerw = FindWindowEx(NULL, hwnd, L"WorkerW", NULL);
		return FALSE;
	}

	return TRUE;
}

void ew::AttachWindow(unsigned char* handleBuffer) {
	auto handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	auto hwnd = (HWND)(LONG_PTR)handle;

	auto progman = FindWindow(L"Progman", NULL);
	auto result = SendMessageTimeout(
		progman,
		WM_SPAWN_WORKER,
		NULL,
		NULL,
		SMTO_NORMAL,
		1000,
		NULL);

	if (!result) {
		// TODO(robin): GetLastError() and handle properly
	}

	// TODO(robin): Handle return value of EnumWindows
	EnumWindows(&FindWorkerW, reinterpret_cast<LPARAM>(&workerw));

	// Update style of the Window we want to attach
	SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_LAYERED);
	SetParent(hwnd, workerw);
}

void ew::DetachWindow(unsigned char* handleBuffer) {
	LONG_PTR handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	HWND hwnd = (HWND)(LONG_PTR)handle;

	// TODO(robin): Remove the style update we applied

	SetParent(hwnd, workerw);
}

Napi::Value ew::AttachWindowExport(const Napi::CallbackInfo& info) {
	auto env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsBuffer()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();

	AttachWindow(windowHandleBuffer.Data());
	return env.Null();
}

Napi::Value ew::DetachWindowExport(const Napi::CallbackInfo& info) {
	auto env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsBuffer()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();

	DetachWindow(windowHandleBuffer.Data());
	return env.Null();
}