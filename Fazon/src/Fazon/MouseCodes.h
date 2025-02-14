#pragma once

#include "Fazon/Core.h"

namespace Fazon {

	using MouseCode = uint16_t;

	namespace Button {

		enum : MouseCode {

			Left		= BIT(0),	// 0000 0000 0000 0001
			Right		= BIT(1),	// 0000 0000 0000 0010
			Middle		= BIT(2),	// 0000 0000 0000 0100
			Back		= BIT(3),	// 0000 0000 0000 1000
			Forward		= BIT(4),	// 0000 0000 0001 0000
			Button6		= BIT(5),	// 0000 0000 0010 0000
			Button7		= BIT(6),	// 0000 0000 0100 0000
			Button8		= BIT(7),	// 0000 0000 1000 0000
			Button9		= BIT(8),	// 0000 0001 0000 0000
			Button10	= BIT(9),	// 0000 0010 0000 0000
			Button11	= BIT(10),	// 0000 0100 0000 0000
			Button12	= BIT(11),	// 0000 1000 0000 0000
			Button13	= BIT(12),	// 0001 0000 0000 0000
			Button14	= BIT(13),	// 0010 0000 0000 0000
			Button15	= BIT(14),	// 0100 0000 0000 0000
			Button16	= BIT(15)	// 1000 0000 0000 0000

		};

	}

}