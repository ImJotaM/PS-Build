#pragma once
#include "Core.h"

namespace GuidSys {

	inline std::string GenerateGuid() {
		
		HRESULT hr = CoInitialize(NULL);

		if (FAILED(hr)) return std::string();

		GUID guid;
		hr = CoCreateGuid(&guid);

		if (FAILED(hr)) {
			CoUninitialize();
			return std::string();
		}

		CoUninitialize();

		std::ostringstream oss;

		oss << std::hex << std::uppercase << "{"
			<< guid.Data1 << "-"
			<< guid.Data2 << "-"
			<< guid.Data3 << "-"
			<< static_cast<int>(guid.Data4[0] << 8 | guid.Data4[1]) << "-"
			<< std::hex;

		for (size_t i = 2; i < 8; ++i)
			oss << static_cast<int>(guid.Data4[i]);

		oss << "}";

		return oss.str();
	}

}