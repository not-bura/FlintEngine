#pragma once

#include "Domain/UTF8/UTF8.h"

namespace FlintEngine
{
	class CUI
	{
	private:
		CUI();
		~CUI();

	public:
		static bool Start(CUI* out);

		void Pause() const;

		void WriteLine(const char* source) const;
		//void WriteLine(const UTF8String& source) const;
	};
}