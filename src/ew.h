/*
 * Copyright 2018 Robin Andersson <me@robinwassen.com>
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

#pragma once

#include <napi.h>
#include <windows.h>

namespace ew {
	// Message to Progman to spawn a WorkerW
	static int WM_SPAWN_WORKER = 0x052C;

	// TODO(robin): Use the EnumWindows callback
	// instead of a global
	static HWND workerw = NULL;

	// Window enumerator that will set the
	// window handle for the WorkerW that is the next
	// sibling to SHELLDLL_DefView
	BOOL CALLBACK FindWorkerW(HWND, LPARAM);

	void AttachWindow(unsigned char*);
	void DetachWindow(unsigned char*);

	Napi::Value AttachWindowExport(const Napi::CallbackInfo& info);
	Napi::Value DetachWindowExport(const Napi::CallbackInfo& info);
}  // namespace ew
