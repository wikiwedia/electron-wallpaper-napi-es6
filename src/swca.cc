#include "swca.h"

Napi::Value swca::setComposition(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Value returnValue = Napi::Boolean::New(env, false);

	if (swca::SWCA) {
		auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();
		auto handle = *reinterpret_cast<LONG_PTR*>(windowHandleBuffer.Data());
		auto hwnd = (HWND)(LONG_PTR)handle;

		ACCENTPOLICY policy;
		policy.nAccentState = static_cast<int32_t>(info[1].ToNumber());
		policy.nFlags = 2;
		policy.nColor = static_cast<uint32_t>(info[2].ToNumber());
		policy.nAnimationId = 0;

		WINCOMATTRPDATA data;
		data.nAttribute = WCA_ACCENT_POLICY;
		data.pData = &policy;
		data.ulDataSize = sizeof(policy);

		returnValue = Napi::Boolean::New(env, SWCA(hwnd, &data));
	}

	return returnValue;
}
