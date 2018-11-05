/**
 * @brief Let's play Draw Poker
 * @author Michael Burmeister
 * @date October 23, 2018
 * @version 1.0
 * 
*/

unsigned int Cards[][24] = {{0x3FFFFFF8, 0x40810204, 0xA142850A, 0x92244892, 0x8C183062, 0x8C183062, 0x92244892, 0xA142850A, 0xC0810206, 0xA142850A, 0x92244892, 0x8C183062, 0x8C183062, 0x92244892, 0xA142850A, 0xC0810206, 0xA142850A, 0x92244892, 0x8C183062, 0x8C183062, 0x92244892, 0xA142850A, 0x40810204, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x81000002, 0x8F000002, 0x9D000002, 0xB4000002, 0xB4000002, 0x9D000002, 0x8F038002, 0x8107C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC102, 0x8007C1E2, 0x80038172, 0x8000005A, 0x8000005A, 0x80000172, 0x800001E2, 0x80000102, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x81000002, 0x8F000002, 0x9D000002, 0xB4000002, 0xB4000002, 0x9D0F0002, 0x8F1F8002, 0x811FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8102, 0x800F01E2, 0x80000172, 0x8000005A, 0x8000005A, 0x80000172, 0x800001E2, 0x80000102, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x81000002, 0x8F000002, 0x9D000002, 0xB4000002, 0xB4000002, 0x9D010002, 0x8F038002, 0x8107C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C102, 0x800381E2, 0x80010172, 0x8000005A, 0x8000005A, 0x80000172, 0x800001E2, 0x80000102, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x81000002, 0x8F000002, 0x9D000002, 0xB4000002, 0xB401C002, 0x9D03E002, 0x8F03E002, 0x811DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E102, 0x8003E1E2, 0x8001C172, 0x8000005A, 0x8000005A, 0x80000172, 0x800001E2, 0x80000102, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x93800002, 0xA2800002, 0xA4800002, 0xA4800002, 0x98800002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x80038232, 0x8000024A, 0x8000024A, 0x8000028A, 0x80000392, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x93800002, 0xA2800002, 0xA4800002, 0xA4800002, 0x988F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x80000232, 0x8000024A, 0x8000024A, 0x8000028A, 0x80000392, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x93800002, 0xA2800002, 0xA4800002, 0xA4800002, 0x98810002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x80010232, 0x8000024A, 0x8000024A, 0x8000028A, 0x80000392, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x93800002, 0xA2800002, 0xA4800002, 0xA481C002, 0x9883E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C232, 0x8000024A, 0x8000024A, 0x8000028A, 0x80000392, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0800002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x800381B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000020A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0800002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B0F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x800001B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000020A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0800002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x800101B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000020A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0800002, 0xA4800002, 0xA4800002, 0xA481C002, 0x9B03E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C1B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000020A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x84000002, 0x8C000002, 0x94000002, 0xA4000002, 0xBF800002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x800383FA, 0x8000004A, 0x80000052, 0x80000062, 0x80000042, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x84000002, 0x8C000002, 0x94000002, 0xA4000002, 0xBF8F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x800003FA, 0x8000004A, 0x80000052, 0x80000062, 0x80000042, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x84000002, 0x8C000002, 0x94000002, 0xA4000002, 0xBF810002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x800103FA, 0x8000004A, 0x80000052, 0x80000062, 0x80000042, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x84000002, 0x8C000002, 0x94000002, 0xA401C002, 0xBF83E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C3FA, 0x8000004A, 0x80000052, 0x80000062, 0x80000042, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBC800002, 0xA4800002, 0xA4800002, 0xA4800002, 0xA3000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x8003818A, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000027A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBC800002, 0xA4800002, 0xA4800002, 0xA4800002, 0xA30F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x8000018A, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000027A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBC800002, 0xA4800002, 0xA4800002, 0xA4800002, 0xA3010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x8001018A, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000027A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBC800002, 0xA4800002, 0xA4800002, 0xA481C002, 0xA303E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C18A, 0x8000024A, 0x8000024A, 0x8000024A, 0x8000027A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x83000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x80038182, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x830F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x80000182, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x83010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x80010182, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA4800002, 0xA4800002, 0xA481C002, 0x8303E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C182, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0000002, 0xA0000002, 0xA7800002, 0xA8000002, 0xB0000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x8003801A, 0x8000002A, 0x800003CA, 0x8000000A, 0x8000000A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0000002, 0xA0000002, 0xA7800002, 0xA8000002, 0xB00F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x8000001A, 0x8000002A, 0x800003CA, 0x8000000A, 0x8000000A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0000002, 0xA0000002, 0xA7800002, 0xA8000002, 0xB0010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x8001001A, 0x8000002A, 0x800003CA, 0x8000000A, 0x8000000A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xA0000002, 0xA0000002, 0xA7800002, 0xA801C002, 0xB003E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C01A, 0x8000002A, 0x800003CA, 0x8000000A, 0x8000000A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9B000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x800381B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001B2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9B000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B0F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x800001B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001B2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9B000002, 0xA4800002, 0xA4800002, 0xA4800002, 0x9B010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x800101B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001B2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9B000002, 0xA4800002, 0xA4800002, 0xA481C002, 0x9B03E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C1B2, 0x8000024A, 0x8000024A, 0x8000024A, 0x800001B2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBD000002, 0xA5000002, 0xA5000002, 0xBF000002, 0x80000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x80038002, 0x800001FA, 0x8000014A, 0x8000014A, 0x8000017A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBD000002, 0xA5000002, 0xA5000002, 0xBF000002, 0x800F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x80000002, 0x800001FA, 0x8000014A, 0x8000014A, 0x8000017A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBD000002, 0xA5000002, 0xA5000002, 0xBF000002, 0x80010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x80010002, 0x800001FA, 0x8000014A, 0x8000014A, 0x8000017A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBD000002, 0xA5000002, 0xA5000002, 0xBF01C002, 0x8003E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C002, 0x800001FA, 0x8000014A, 0x8000014A, 0x8000017A, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF000002, 0x80000002, 0x9E000002, 0xA1000002, 0xA1000002, 0x9E038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C0F2, 0x8003810A, 0x8000010A, 0x800000F2, 0x80000002, 0x800001FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF000002, 0x80000002, 0x9E000002, 0xA1000002, 0xA10F0002, 0x9E1F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F00F2, 0x8000010A, 0x8000010A, 0x800000F2, 0x80000002, 0x800001FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF000002, 0x80000002, 0x9E000002, 0xA1000002, 0xA1010002, 0x9E038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x800380F2, 0x8001010A, 0x8000010A, 0x800000F2, 0x80000002, 0x800001FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF000002, 0x80000002, 0x9E000002, 0xA101C002, 0xA103E002, 0x9E03E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E0F2, 0x8001C10A, 0x8000010A, 0x800000F2, 0x80000002, 0x800001FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x83000002, 0x80800002, 0xA0800002, 0xBF000002, 0xA0000002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x8003800A, 0x800001FA, 0x8000020A, 0x80000202, 0x80000182, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x83000002, 0x80800002, 0xA0800002, 0xBF000002, 0xA00F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x8000000A, 0x800001FA, 0x8000020A, 0x80000202, 0x80000182, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x83000002, 0x80800002, 0xA0800002, 0xBF000002, 0xA0010002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x8001000A, 0x800001FA, 0x8000020A, 0x80000202, 0x80000182, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x83000002, 0x80800002, 0xA0800002, 0xBF01C002, 0xA003E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C00A, 0x800001FA, 0x8000020A, 0x80000202, 0x80000182, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA0800002, 0xA2800002, 0xA1000002, 0x9E800002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x800382F2, 0x8000010A, 0x8000028A, 0x8000020A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA0800002, 0xA2800002, 0xA1000002, 0x9E8F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x800002F2, 0x8000010A, 0x8000028A, 0x8000020A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA0800002, 0xA2800002, 0xA1000002, 0x9E810002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x800102F2, 0x8000010A, 0x8000028A, 0x8000020A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0x9F000002, 0xA0800002, 0xA2800002, 0xA101C002, 0x9E83E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C2F2, 0x8000010A, 0x8000028A, 0x8000020A, 0x800001F2, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF800002, 0x84000002, 0x8A000002, 0x91000002, 0xA0800002, 0x80038002, 0x8007C002, 0x800FC002, 0x801F9002, 0x803FF002, 0x801F9002, 0x800FC002, 0x8007C002, 0x8003820A, 0x80000112, 0x800000A2, 0x80000042, 0x800003FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF800002, 0x84000002, 0x8A000002, 0x91000002, 0xA08F0002, 0x801F8002, 0x801FC002, 0x800FE002, 0x8007F002, 0x800FE002, 0x801FC002, 0x801F8002, 0x800F0002, 0x8000020A, 0x80000112, 0x800000A2, 0x80000042, 0x800003FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF800002, 0x84000002, 0x8A000002, 0x91000002, 0xA0810002, 0x80038002, 0x8007C002, 0x800FE002, 0x801FF002, 0x801FF002, 0x800FE002, 0x8007C002, 0x80038002, 0x8001020A, 0x80000112, 0x800000A2, 0x80000042, 0x800003FA, 0x80000002, 0x40000004, 0x3FFFFFF8},
{0x3FFFFFF8, 0x40000004, 0x80000002, 0xBF800002, 0x84000002, 0x8A000002, 0x9101C002, 0xA083E002, 0x8003E002, 0x801DE002, 0x803FC802, 0x803FF802, 0x803FC802, 0x801DE002, 0x8003E002, 0x8003E002, 0x8001C20A, 0x80000112, 0x800000A2, 0x80000042, 0x800003FA, 0x80000002, 0x40000004, 0x3FFFFFF8}};

