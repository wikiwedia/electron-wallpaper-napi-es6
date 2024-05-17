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

#include <assert.h>
#include "ew.h"
#include "napi.h"
#include "swca.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "attachWindow"), Napi::Function::New(env, ew::AttachWindowExport));
	exports.Set(Napi::String::New(env, "detachWindow"), Napi::Function::New(env, ew::DetachWindowExport));
	exports.Set(Napi::String::New(env, "setComposition"), Napi::Function::New(env, swca::setComposition));
	return exports;
}

NODE_API_MODULE(addon, Init)