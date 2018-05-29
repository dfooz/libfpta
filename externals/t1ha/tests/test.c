/*
 *  Copyright (c) 2016-2018 Positive Technologies, https://www.ptsecurity.com,
 *  Fast Positive Hash.
 *
 *  Portions Copyright (c) 2010-2018 Leonid Yuriev <leo@yuriev.ru>,
 *  The 1Hippeus project (t1h).
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgement in the product documentation would be
 *     appreciated but is not required.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
 */

#include "common.h"
#include <stdio.h>

#if defined(_MSC_VER)
#if _MSC_VER < 1900
#define snprintf _snprintf
#pragma warning(disable : 4996) /* '_snprintf': This function or variable      \
                                   may be unsafe */
#endif
#endif /* MSVC */

/*****************************************************************************/

/* *INDENT-OFF* */
/* clang-format off */
static const uint8_t pattern[64] = {
  0, 1, 2, 3, 4, 5, 6, 7, 0xFF, 0x7F, 0x3F, 0x1F, 0xF, 8, 16, 32, 64, 0x80, 0xFE,
  0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x55, 0xAA,
  11, 17, 19, 23, 29, 37, 42, 43, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'
};

#ifndef T1HA2_DISABLED
const uint64_t refval_2atonce[81] = { 0,
  0x772C7311BE32FF42, 0x444753D23F207E03, 0x71F6DF5DA3B4F532, 0x555859635365F660,
  0xE98808F1CD39C626, 0x2EB18FAF2163BB09, 0x7B9DD892C8019C87, 0xE2B1431C4DA4D15A,
  0x1984E718A5477F70, 0x08DD17B266484F79, 0x4C83A05D766AD550, 0x92DCEBB131D1907D,
  0xD67BC6FC881B8549, 0xF6A9886555FBF66B, 0x6E31616D7F33E25E, 0x36E31B7426E3049D,
  0x4F8E4FAF46A13F5F, 0x03EB0CB3253F819F, 0x636A7769905770D2, 0x3ADF3781D16D1148,
  0x92D19CB1818BC9C2, 0x283E68F4D459C533, 0xFA83A8A88DECAA04, 0x8C6F00368EAC538C,
  0x7B66B0CF3797B322, 0x5131E122FDABA3FF, 0x6E59FF515C08C7A9, 0xBA2C5269B2C377B0,
  0xA9D24FD368FE8A2B, 0x22DB13D32E33E891, 0x7B97DFC804B876E5, 0xC598BDFCD0E834F9,
  0xB256163D3687F5A7, 0x66D7A73C6AEF50B3, 0x25A7201C85D9E2A3, 0x911573EDA15299AA,
  0x5C0062B669E18E4C, 0x17734ADE08D54E28, 0xFFF036E33883F43B, 0xFE0756E7777DF11E,
  0x37972472D023F129, 0x6CFCE201B55C7F57, 0xE019D1D89F02B3E1, 0xAE5CC580FA1BB7E6,
  0x295695FB7E59FC3A, 0x76B6C820A40DD35E, 0xB1680A1768462B17, 0x2FB6AF279137DADA,
  0x28FB6B4366C78535, 0xEC278E53924541B1, 0x164F8AAB8A2A28B5, 0xB6C330AEAC4578AD,
  0x7F6F371070085084, 0x94DEAD60C0F448D3, 0x99737AC232C559EF, 0x6F54A6F9CA8EDD57,
  0x979B01E926BFCE0C, 0xF7D20BC85439C5B4, 0x64EDB27CD8087C12, 0x11488DE5F79C0BE2,
  0x25541DDD1680B5A4, 0x8B633D33BE9D1973, 0x404A3113ACF7F6C6, 0xC59DBDEF8550CD56,
  0x039D23C68F4F992C, 0x5BBB48E4BDD6FD86, 0x41E312248780DF5A, 0xD34791CE75D4E94F,
  0xED523E5D04DCDCFF, 0x7A6BCE0B6182D879, 0x21FB37483CAC28D8, 0x19A1B66E8DA878AD,
  0x6F804C5295B09ABE, 0x2A4BE5014115BA81, 0xA678ECC5FC924BE0, 0x50F7A54A99A36F59,
  0x0FD7E63A39A66452, 0x5AB1B213DD29C4E4, 0xF3ED80D9DF6534C5, 0xC736B12EF90615FD
};

const uint64_t refval_2atonce128[81] = { 0x4EC7F6A48E33B00A,
  0xB7B7FAA5BD7D8C1E, 0x3269533F66534A76, 0x6C3EC6B687923BFC, 0xC096F5E7EFA471A9,
  0x79D8AFB550CEA471, 0xCEE0507A20FD5119, 0xFB04CFFC14A9F4BF, 0xBD4406E923807AF2,
  0x375C02FF11010491, 0xA6EA4C2A59E173FF, 0xE0A606F0002CADDF, 0xE13BEAE6EBC07897,
  0xF069C2463E48EA10, 0x75BEE1A97089B5FA, 0x378F22F8DE0B8085, 0x9C726FC4D53D0D8B,
  0x71F6130A2D08F788, 0x7A9B20433FF6CF69, 0xFF49B7CD59BF6D61, 0xCCAAEE0D1CA9C6B3,
  0xC77889D86039D2AD, 0x7B378B5BEA9B0475, 0x6520BFA79D59AD66, 0x2441490CB8A37267,
  0xA715A66B7D5CF473, 0x9AE892C88334FD67, 0xD2FFE9AEC1D2169A, 0x790B993F18B18CBB,
  0xA0D02FBCF6A7B1AD, 0xA90833E6F151D0C1, 0x1AC7AFA37BD79BE0, 0xD5383628B2881A24,
  0xE5526F9D63F9F8F1, 0xC1F165A01A6D1F4D, 0x6CCEF8FF3FCFA3F2, 0x2030F18325E6DF48,
  0x289207230E3FB17A, 0x077B66F713A3C4B9, 0x9F39843CAF871754, 0x512FDA0F808ACCF3,
  0xF4D9801CD0CD1F14, 0x28A0C749ED323638, 0x94844CAFA671F01C, 0xD0E261876B8ACA51,
  0x8FC2A648A4792EA2, 0x8EF87282136AF5FE, 0x5FE6A54A9FBA6B40, 0xA3CC5B8FE6223D54,
  0xA8C3C0DD651BB01C, 0x625E9FDD534716F3, 0x1AB2604083C33AC5, 0xDE098853F8692F12,
  0x4B0813891BD87624, 0x4AB89C4553D182AD, 0x92C15AA2A3C27ADA, 0xFF2918D68191F5D9,
  0x06363174F641C325, 0x667112ADA74A2059, 0x4BD605D6B5E53D7D, 0xF2512C53663A14C8,
  0x21857BCB1852667C, 0xAFBEBD0369AEE228, 0x7049340E48FBFD6B, 0x50710E1924F46954,
  0x869A75E04A976A3F, 0x5A41ABBDD6373889, 0xA781778389B4B188, 0x21A3AFCED6C925B6,
  0x107226192EC10B42, 0x62A862E84EC2F9B1, 0x2B15E91659606DD7, 0x613934D1F9EC5A42,
  0x4DC3A96DC5361BAF, 0xC80BBA4CB5F12903, 0x3E3EDAE99A7D6987, 0x8F97B2D55941DCB0,
  0x4C9787364C3E4EC1, 0xEF0A2D07BEA90CA7, 0x5FABF32C70AEEAFB, 0x3356A5CFA8F23BF4
};

const uint64_t refval_2stream[81] = { 0x3C8426E33CB41606,
  0xFD74BE70EE73E617, 0xF43DE3CDD8A20486, 0x882FBCB37E8EA3BB, 0x1AA2CDD34CAA3D4B,
  0xEE755B2BFAE07ED5, 0xD4E225250D92E213, 0xA09B49083205965B, 0xD47B21724EF9EC9E,
  0xAC888FC3858CEE11, 0x94F820D85736F244, 0x1707951CCA920932, 0x8E0E45603F7877F0,
  0x9FD2592C0E3A7212, 0x9A66370F3AE3D427, 0xD33382D2161DE2B7, 0x9A35BE079DA7115F,
  0x73457C7FF58B4EC3, 0xBE8610BD53D7CE98, 0x65506DFE5CCD5371, 0x286A321AF9D5D9FA,
  0xB81EF9A7EF3C536D, 0x2CFDB5E6825C6E86, 0xB2A58CBFDFDD303A, 0xD26094A42B950635,
  0xA34D666A5F02AD9A, 0x0151E013EBCC72E5, 0x9254A6EA7FCB6BB5, 0x10C9361B3869DC2B,
  0xD7EC55A060606276, 0xA2FF7F8BF8976FFD, 0xB5181BB6852DCC88, 0x0EE394BB6178BAFF,
  0x3A8B4B400D21B89C, 0xEC270461970960FD, 0x615967FAB053877E, 0xFA51BF1CFEB4714C,
  0x29FDA8383070F375, 0xC3B663061BC52EDA, 0x192BBAF1F1A57923, 0x6D193B52F93C53AF,
  0x7F6F5639FE87CA1E, 0x69F7F9140B32EDC8, 0xD0F2416FB24325B6, 0x62C0E37FEDD49FF3,
  0x57866A4B809D373D, 0x9848D24BD935E137, 0xDFC905B66734D50A, 0x9A938DD194A68529,
  0x8276C44DF0625228, 0xA4B35D00AD67C0AB, 0x3D9CB359842DB452, 0x4241BFA8C23B267F,
  0x650FA517BEF15952, 0x782DE2ABD8C7B1E1, 0x4EAE456166CA3E15, 0x40CDF3A02614E337,
  0xAD84092C46102172, 0x0C68479B03F9A167, 0x7E1BA046749E181C, 0x3F3AB41A697382C1,
  0xC5E5DD6586EBFDC4, 0xFF926CD4EB02555C, 0x035CFE67F89E709B, 0x89F06AB6464A1B9D,
  0x8EFF58F3F7DEA758, 0x8B54AC657902089F, 0xC6C4F1F9F8DA4D64, 0xBDB729048AAAC93A,
  0xEA76BA628F5E5CD6, 0x742159B728B8A979, 0x6D151CD3C720E53D, 0xE97FFF9368FCDC42,
  0xCA5B38314914FBDA, 0xDD92C91D8B858EAE, 0x66E5F07CF647CBF2, 0xD4CF9B42F4985AFB,
  0x72AE17AC7D92F6B7, 0xB8206B22AB0472E1, 0x385876B5CFD42479, 0x03294A249EBE6B26
};

const uint64_t refval_2stream128[81] = { 0xCD2801D3B92237D6,
  0x10E4D47BD821546D, 0x9100704B9D65CD06, 0xD6951CB4016313EF, 0x24DB636F96F474DA,
  0x3F4AF7DF3C49E422, 0xBFF25B8AF143459B, 0xA157EC13538BE549, 0xD3F5F52C47DBD419,
  0x0EF3D7D735AF1575, 0x46B7B892823F7B1B, 0xEE22EA4655213289, 0x56AD76F02FE929BC,
  0x9CF6CD1AC886546E, 0xAF45CE47AEA0B933, 0x535F9DC09F3996B7, 0x1F0C3C01694AE128,
  0x18495069BE0766F7, 0x37E5FFB3D72A4CB1, 0x6D6C2E9299F30709, 0x4F39E693F50B41E3,
  0xB11FC4EF0658E116, 0x48BFAACB78E5079B, 0xE1B4C89C781B3AD0, 0x81D2F34888D333A1,
  0xF6D02270D2EA449C, 0xC884C3C2C3CE1503, 0x711AE16BA157A9B9, 0x1E6140C642558C9D,
  0x35AB3D238F5DC55B, 0x33F07B6AEF051177, 0xE57336776EEFA71C, 0x6D445F8318BA3752,
  0xD4F5F6631934C988, 0xD5E260085727C4A2, 0x5B54B41EC180B4FA, 0x7F5D75769C15A898,
  0xAE5A6DB850CA33C6, 0x038CCB8044663403, 0xDA16310133DC92B8, 0x6A2FFB7AB2B7CE2B,
  0xDC1832D9229BAE20, 0x8C62C479F5ABC9E4, 0x5EB7B617857C9CCB, 0xB79CF7D749A1E80D,
  0xDE7FAC3798324FD3, 0x8178911813685D06, 0x6A726CBD394D4410, 0x6CBE6B3280DA1113,
  0x6829BA4410CF1148, 0xFA7E417EB26C5BC6, 0x22ED87884D6E3A49, 0x15F1472D5115669D,
  0x2EA0B4C8BF69D318, 0xDFE87070AA545503, 0x6B4C14B5F7144AB9, 0xC1ED49C06126551A,
  0x351919FC425C3899, 0x7B569C0FA6F1BD3E, 0x713AC2350844CFFD, 0xE9367F9A638C2FF3,
  0x97F17D325AEA0786, 0xBCB907CC6CF75F91, 0x0CB7517DAF247719, 0xBE16093CC45BE8A9,
  0x786EEE97359AD6AB, 0xB7AFA4F326B97E78, 0x2694B67FE23E502E, 0x4CB492826E98E0B4,
  0x838D119F74A416C7, 0x70D6A91E4E5677FD, 0xF3E4027AD30000E6, 0x9BDF692795807F77,
  0x6A371F966E034A54, 0x8789CF41AE4D67EF, 0x02688755484D60AE, 0xD5834B3A4BF5CE42,
  0x9405FC61440DE25D, 0x35EB280A157979B6, 0x48D40D6A525297AC, 0x6A87DC185054BADA
};
#endif /* T1HA2_DISABLED */

#ifndef T1HA1_DISABLED
const uint64_t refval_64le[81] = { 0,
  0x6A580668D6048674, 0xA2FE904AFF0D0879, 0xE3AB9C06FAF4D023, 0x6AF1C60874C95442,
  0xB3557E561A6C5D82, 0x0AE73C696F3D37C0, 0x5EF25F7062324941, 0x9B784F3B4CE6AF33,
  0x6993BB206A74F070, 0xF1E95DF109076C4C, 0x4E1EB70C58E48540, 0x5FDD7649D8EC44E4,
  0x559122C706343421, 0x380133D58665E93D, 0x9CE74296C8C55AE4, 0x3556F9A5757AB6D0,
  0xF62751F7F25C469E, 0x851EEC67F6516D94, 0xED463EE3848A8695, 0xDC8791FEFF8ED3AC,
  0x2569C744E1A282CF, 0xF90EB7C1D70A80B9, 0x68DFA6A1B8050A4C, 0x94CCA5E8210D2134,
  0xF5CC0BEABC259F52, 0x40DBC1F51618FDA7, 0x0807945BF0FB52C6, 0xE5EF7E09DE70848D,
  0x63E1DF35FEBE994A, 0x2025E73769720D5A, 0xAD6120B2B8A152E1, 0x2A71D9F13959F2B7,
  0x8A20849A27C32548, 0x0BCBC9FE3B57884E, 0x0E028D255667AEAD, 0xBE66DAD3043AB694,
  0xB00E4C1238F9E2D4, 0x5C54BDE5AE280E82, 0x0E22B86754BC3BC4, 0x016707EBF858B84D,
  0x990015FBC9E095EE, 0x8B9AF0A3E71F042F, 0x6AA56E88BD380564, 0xAACE57113E681A0F,
  0x19F81514AFA9A22D, 0x80DABA3D62BEAC79, 0x715210412CABBF46, 0xD8FA0B9E9D6AA93F,
  0x6C2FC5A4109FD3A2, 0x5B3E60EEB51DDCD8, 0x0A7C717017756FE7, 0xA73773805CA31934,
  0x4DBD6BB7A31E85FD, 0x24F619D3D5BC2DB4, 0x3E4AF35A1678D636, 0x84A1A8DF8D609239,
  0x359C862CD3BE4FCD, 0xCF3A39F5C27DC125, 0xC0FF62F8FD5F4C77, 0x5E9F2493DDAA166C,
  0x17424152BE1CA266, 0xA78AFA5AB4BBE0CD, 0x7BFB2E2CEF118346, 0x647C3E0FF3E3D241,
  0x0352E4055C13242E, 0x6F42FC70EB660E38, 0x0BEBAD4FABF523BA, 0x9269F4214414D61D,
  0x1CA8760277E6006C, 0x7BAD25A859D87B5D, 0xAD645ADCF7414F1D, 0xB07F517E88D7AFB3,
  0xB321C06FB5FFAB5C, 0xD50F162A1EFDD844, 0x1DFD3D1924FBE319, 0xDFAEAB2F09EF7E78,
  0xA7603B5AF07A0B1E, 0x41CD044C0E5A4EE3, 0xF64D2F86E813BF33, 0xFF9FDB99305EB06A
};

const uint64_t refval_64be[81] = { 0,
  0x6A580668D6048674, 0xDECC975A0E3B8177, 0xE3AB9C06FAF4D023, 0xE401FA8F1B6AF969,
  0x67DB1DAE56FB94E3, 0x1106266A09B7A073, 0x550339B1EF2C7BBB, 0x290A2BAF590045BB,
  0xA182C1258C09F54A, 0x137D53C34BE7143A, 0xF6D2B69C6F42BEDC, 0x39643EAF2CA2E4B4,
  0x22A81F139A2C9559, 0x5B3D6AEF0AF33807, 0x56E3F80A68643C08, 0x9E423BE502378780,
  0xCDB0986F9A5B2FD5, 0xD5B3C84E7933293F, 0xE5FB8C90399E9742, 0x5D393C1F77B2CF3D,
  0xC8C82F5B2FF09266, 0xACA0230CA6F7B593, 0xCB5805E2960D1655, 0x7E2AD5B704D77C95,
  0xC5E903CDB8B9EB5D, 0x4CC7D0D21CC03511, 0x8385DF382CFB3E93, 0xF17699D0564D348A,
  0xF77EE7F8274A4C8D, 0xB9D8CEE48903BABE, 0xFE0EBD2A82B9CFE9, 0xB49FB6397270F565,
  0x173735C8C342108E, 0xA37C7FBBEEC0A2EA, 0xC13F66F462BB0B6E, 0x0C04F3C2B551467E,
  0x76A9CB156810C96E, 0x2038850919B0B151, 0xCEA19F2B6EED647B, 0x6746656D2FA109A4,
  0xF05137F221007F37, 0x892FA9E13A3B4948, 0x4D57B70D37548A32, 0x1A7CFB3D566580E6,
  0x7CB30272A45E3FAC, 0x137CCFFD9D51423F, 0xB87D96F3B82DF266, 0x33349AEE7472ED37,
  0x5CC0D3C99555BC07, 0x4A8F4FA196D964EF, 0xE82A0D64F281FBFA, 0x38A1BAC2C36823E1,
  0x77D197C239FD737E, 0xFB07746B4E07DF26, 0xC8A2198E967672BD, 0x5F1A146D143FA05A,
  0x26B877A1201AB7AC, 0x74E5B145214723F8, 0xE9CE10E3C70254BC, 0x299393A0C05B79E8,
  0xFD2D2B9822A5E7E2, 0x85424FEA50C8E50A, 0xE6839E714B1FFFE5, 0x27971CCB46F9112A,
  0xC98695A2E0715AA9, 0x338E1CBB4F858226, 0xFC6B5C5CF7A8D806, 0x8973CAADDE8DA50C,
  0x9C6D47AE32EBAE72, 0x1EBF1F9F21D26D78, 0x80A9704B8E153859, 0x6AFD20A939F141FB,
  0xC35F6C2B3B553EEF, 0x59529E8B0DC94C1A, 0x1569DF036EBC4FA1, 0xDA32B88593C118F9,
  0xF01E4155FF5A5660, 0x765A2522DCE2B185, 0xCEE95554128073EF, 0x60F072A5CA51DE2F
};
#endif /* T1HA1_DISABLED */

#ifndef T1HA0_DISABLED
const uint64_t refval_32le[81] = { 0,
  0xC92229C10FAEA50E, 0x3DF1354B0DFDC443, 0x968F016D60417BB3, 0x85AAFB50C6DA770F,
  0x66CCE3BB6842C7D6, 0xDDAA39C11537C226, 0x35958D281F0C9C8C, 0x8C5D64B091DE608E,
  0x4094DF680D39786B, 0x1014F4AA2A2EDF4D, 0x39D21891615AA310, 0x7EF51F67C398C7C4,
  0x06163990DDBF319D, 0xE229CAA00C8D6F3F, 0xD2240B4B0D54E0F5, 0xEA2E7E905DDEAF94,
  0x8D4F8A887183A5CE, 0x44337F9A63C5820C, 0x94938D1E86A9B797, 0x96E9CABA5CA210CC,
  0x6EFBB9CC9E8F7708, 0x3D12EA0282FB8BBC, 0x5DA781EE205A2C48, 0xFA4A51A12677FE12,
  0x81D5F04E20660B28, 0x57258D043BCD3841, 0x5C9BEB62059C1ED2, 0x57A02162F9034B33,
  0xBA2A13E457CE19B8, 0xE593263BF9451F3A, 0x0BC1175539606BC5, 0xA3E2929E9C5F289F,
  0x86BDBD06835E35F7, 0xA180950AB48BAADC, 0x7812C994D9924028, 0x308366011415F46B,
  0x77FE9A9991C5F959, 0x925C340B70B0B1E3, 0xCD9C5BA4C41E2E10, 0x7CC4E7758B94CD93,
  0x898B235962EA4625, 0xD7E3E5BF22893286, 0x396F4CDD33056C64, 0x740AB2E32F17CD9F,
  0x60D12FF9CD15B321, 0xBEE3A6C9903A81D8, 0xB47040913B33C35E, 0x19EE8C2ACC013CFF,
  0x5DEC94C5783B55C4, 0x78DC122D562C5F1D, 0x6520F008DA1C181E, 0x77CAF155A36EBF7C,
  0x0A09E02BDB883CA6, 0xFD5D9ADA7E3FB895, 0xC6F5FDD9EEAB83B5, 0x84589BB29F52A92A,
  0x9B2517F13F8E9814, 0x6F752AF6A52E31EC, 0x8E717799E324CE8A, 0x84D90AEF39262D58,
  0x79C27B13FC28944D, 0xE6D6DF6438E0044A, 0x51B603E400D79CA4, 0x6A902B28C588B390,
  0x8D7F8DE9E6CB1D83, 0xCF1A4DC11CA7F044, 0xEF02E43C366786F1, 0x89915BCDBCFBE30F,
  0x5928B306F1A9CC7F, 0xA8B59092996851C5, 0x22050A20427E8B25, 0x6E6D64018941E7EE,
  0x9798C898B81AE846, 0x80EF218CDC30124A, 0xFCE45E60D55B0284, 0x4010E735D3147C35,
  0xEB647D999FD8DC7E, 0xD3544DCAB14FE907, 0xB588B27D8438700C, 0xA49EBFC43E057A4C
};

const uint64_t refval_32be[81] = { 0,
  0xC92229C10FAEA50E, 0x0FE212630DD87E0F, 0x968F016D60417BB3, 0xE6B12B2C889913AB,
  0xAA3787887A9DA368, 0x06EE7202D53CEF39, 0x6149AFB2C296664B, 0x86C893210F9A5805,
  0x8379E5DA988AA04C, 0x24763AA7CE411A60, 0x9CF9C64B395A4CF8, 0xFFC192C338DDE904,
  0x094575BAB319E5F5, 0xBBBACFE7728C6511, 0x36B8C3CEBE4EF409, 0xAA0BA8A3397BA4D0,
  0xF9F85CF7124EE653, 0x3ADF4F7DF2A887AE, 0xAA2A0F5964AA9A7A, 0xF18B563F42D36EB8,
  0x034366CEF8334F5C, 0xAE2E85180E330E5F, 0xA5CE9FBFDF5C65B8, 0x5E509F25A9CA9B0B,
  0xE30D1358C2013BD2, 0xBB3A04D5EB8111FE, 0xB04234E82A15A28D, 0x87426A56D0EA0E2F,
  0x095086668E07F9F8, 0xF4CD3A43B6A6AEA5, 0x73F9B9B674D472A6, 0x558344229A1E4DCF,
  0x0AD4C95B2279181A, 0x5E3D19D80821CA6B, 0x652492D25BEBA258, 0xEFA84B02EAB849B1,
  0x81AD2D253059AC2C, 0x1400CCB0DFB2F457, 0x5688DC72A839860E, 0x67CC130E0FD1B0A7,
  0x0A851E3A94E21E69, 0x2EA0000B6A073907, 0xAE9776FF9BF1D02E, 0xC0A96B66B160631C,
  0xA93341DE4ED7C8F0, 0x6FBADD8F5B85E141, 0xB7D295F1C21E0CBA, 0x6D6114591B8E434F,
  0xF5B6939B63D97BE7, 0x3C80D5053F0E5DB4, 0xAC520ACC6B73F62D, 0xD1051F5841CF3966,
  0x62245AEA644AE760, 0x0CD56BE15497C62D, 0x5BB93435C4988FB6, 0x5FADB88EB18DB512,
  0xC897CAE2242475CC, 0xF1A094EF846DC9BB, 0x2B1D8B24924F79B6, 0xC6DF0C0E8456EB53,
  0xE6A40128303A9B9C, 0x64D37AF5EFFA7BD9, 0x90FEB70A5AE2A598, 0xEC3BA5F126D9FF4B,
  0x3121C8EC3AC51B29, 0x3B41C4D422166EC1, 0xB4878DDCBF48ED76, 0x5CB850D77CB762E4,
  0x9A27A43CC1DD171F, 0x2FDFFC6F99CB424A, 0xF54A57E09FDEA7BB, 0x5F78E5EE2CAB7039,
  0xB8BA95883DB31CBA, 0x131C61EB84AF86C3, 0x84B1F64E9C613DA7, 0xE94C1888C0C37C02,
  0xEA08F8BFB2039CDE, 0xCCC6D04D243EC753, 0x8977D105298B0629, 0x7AAA976494A5905E
};

#if T1HA0_AESNI_AVAILABLE
const uint64_t refval_ia32aes_a[81] = { 0,
  0x772C7311BE32FF42, 0xB231AC660E5B23B5, 0x71F6DF5DA3B4F532, 0x555859635365F660,
  0xE98808F1CD39C626, 0x2EB18FAF2163BB09, 0x7B9DD892C8019C87, 0xE2B1431C4DA4D15A,
  0x1984E718A5477F70, 0x08DD17B266484F79, 0x4C83A05D766AD550, 0x92DCEBB131D1907D,
  0xD67BC6FC881B8549, 0xF6A9886555FBF66B, 0x6E31616D7F33E25E, 0x36E31B7426E3049D,
  0x4F8E4FAF46A13F5F, 0x03EB0CB3253F819F, 0x636A7769905770D2, 0x3ADF3781D16D1148,
  0x92D19CB1818BC9C2, 0x283E68F4D459C533, 0xFA83A8A88DECAA04, 0x8C6F00368EAC538C,
  0x7B66B0CF3797B322, 0x5131E122FDABA3FF, 0x6E59FF515C08C7A9, 0xBA2C5269B2C377B0,
  0xA9D24FD368FE8A2B, 0x22DB13D32E33E891, 0x7B97DFC804B876E5, 0xC598BDFCD0E834F9,
  0xB256163D3687F5A7, 0x66D7A73C6AEF50B3, 0xBB34C6A4396695D2, 0x7F46E1981C3256AD,
  0x4B25A9B217A6C5B4, 0x7A0A6BCDD2321DA9, 0x0A1F55E690A7B44E, 0x8F451A91D7F05244,
  0x624D5D3C9B9800A7, 0x09DDC2B6409DDC25, 0x3E155765865622B6, 0x96519FAC9511B381,
  0x512E58482FE4FBF0, 0x1AB260EA7D54AE1C, 0x67976F12CC28BBBD, 0x0607B5B2E6250156,
  0x7E700BEA717AD36E, 0x06A058D9D61CABB3, 0x57DA5324A824972F, 0x1193BA74DBEBF7E7,
  0xC18DC3140E7002D4, 0x9F7CCC11DFA0EF17, 0xC487D6C20666A13A, 0xB67190E4B50EF0C8,
  0xA53DAA608DF0B9A5, 0x7E13101DE87F9ED3, 0x7F8955AE2F05088B, 0x2DF7E5A097AD383F,
  0xF027683A21EA14B5, 0x9BB8AEC3E3360942, 0x92BE39B54967E7FE, 0x978C6D332E7AFD27,
  0xED512FE96A4FAE81, 0x9E1099B8140D7BA3, 0xDFD5A5BE1E6FE9A6, 0x1D82600E23B66DD4,
  0x3FA3C3B7EE7B52CE, 0xEE84F7D2A655EF4C, 0x2A4361EC769E3BEB, 0x22E4B38916636702,
  0x0063096F5D39A115, 0x6C51B24DAAFA5434, 0xBAFB1DB1B411E344, 0xFF529F161AE0C4B0,
  0x1290EAE3AC0A686F, 0xA7B0D4585447D1BE, 0xAED3D18CB6CCAD53, 0xFC73D46F8B41BEC6
};

const uint64_t refval_ia32aes_b[81] = { 0,
  0x772C7311BE32FF42, 0x4398F62A8CB6F72A, 0x71F6DF5DA3B4F532, 0x555859635365F660,
  0xE98808F1CD39C626, 0x2EB18FAF2163BB09, 0x7B9DD892C8019C87, 0xE2B1431C4DA4D15A,
  0x1984E718A5477F70, 0x08DD17B266484F79, 0x4C83A05D766AD550, 0x92DCEBB131D1907D,
  0xD67BC6FC881B8549, 0xF6A9886555FBF66B, 0x6E31616D7F33E25E, 0x36E31B7426E3049D,
  0x4F8E4FAF46A13F5F, 0x03EB0CB3253F819F, 0x636A7769905770D2, 0x3ADF3781D16D1148,
  0x92D19CB1818BC9C2, 0x283E68F4D459C533, 0xFA83A8A88DECAA04, 0x8C6F00368EAC538C,
  0x7B66B0CF3797B322, 0x5131E122FDABA3FF, 0x6E59FF515C08C7A9, 0xBA2C5269B2C377B0,
  0xA9D24FD368FE8A2B, 0x22DB13D32E33E891, 0x7B97DFC804B876E5, 0xC598BDFCD0E834F9,
  0xB256163D3687F5A7, 0x66D7A73C6AEF50B3, 0xE810F88E85CEA11A, 0x4814F8F3B83E4394,
  0x9CABA22D10A2F690, 0x0D10032511F58111, 0xE9A36EF5EEA3CD58, 0xC79242DE194D9D7C,
  0xC3871AA0435EE5C8, 0x52890BED43CCF4CD, 0x07A1D0861ACCD373, 0x227B816FF0FEE9ED,
  0x59FFBF73AACFC0C4, 0x09AB564F2BEDAD0C, 0xC05F744F2EE38318, 0x7B50B621D547C661,
  0x0C1F71CB4E68E5D1, 0x0E33A47881D4DBAA, 0xF5C3BF198E9A7C2E, 0x16328FD8C0F68A91,
  0xA3E399C9AB3E9A59, 0x163AE71CBCBB18B8, 0x18F17E4A8C79F7AB, 0x9250E2EA37014B45,
  0x7BBBB111D60B03E4, 0x3DAA4A3071A0BD88, 0xA28828D790A2D6DC, 0xBC70FC88F64BE3F1,
  0xA3E48008BA4333C7, 0x739E435ACAFC79F7, 0x42BBB360BE007CC6, 0x4FFB6FD2AF74EC92,
  0x2A799A2994673146, 0xBE0A045B69D48E9F, 0x549432F54FC6A278, 0x371D3C60369FC702,
  0xDB4557D415B08CA7, 0xE8692F0A83850B37, 0x022E46AEB36E9AAB, 0x117AC9B814E4652D,
  0xA361041267AE9048, 0x277CB51C961C3DDA, 0xAFFC96F377CB8A8D, 0x83CC79FA01DD1BA7,
  0xA494842ACF4B802C, 0xFC6D9CDDE2C34A3F, 0x4ED6863CE455F7A7, 0x630914D0DB7AAE98
};
#endif /* T1HA0_AESNI_AVAILABLE */
#endif /* T1HA0_DISABLED */

/* *INDENT-ON* */
/* clang-format on */

/*****************************************************************************/

#ifndef T1HA2_DISABLED
uint64_t thunk_t1ha2_atonce128(const void *data, size_t len, uint64_t seed) {
  uint64_t unused;
  return t1ha2_atonce128(&unused, data, len, seed);
}

uint64_t thunk_t1ha2_stream(const void *data, size_t len, uint64_t seed) {
  t1ha_context_t ctx;
  t1ha2_init(&ctx, seed, seed);
  t1ha2_update(&ctx, data, len);
  return t1ha2_final(&ctx, NULL);
}

uint64_t thunk_t1ha2_stream128(const void *data, size_t len, uint64_t seed) {
  t1ha_context_t ctx;
  t1ha2_init(&ctx, seed, seed);
  t1ha2_update(&ctx, data, len);
  uint64_t unused;
  return t1ha2_final(&ctx, &unused);
}
#endif /* T1HA2_DISABLED */

static bool probe(uint64_t (*hash)(const void *, size_t, uint64_t),
                  const char *caption, const uint64_t check, const void *data,
                  unsigned len, uint64_t seed) {
  uint64_t value = hash(data, len, seed);
  if (is_option_set(test_verbose) || (value != check))
    printf("Pattern '%s', reference value %08X%08X: ", caption,
           (uint32_t)(check >> 32), (uint32_t)check);
  if (check == value) {
    if (is_option_set(test_verbose))
      printf("Passed\n");
    return false;
  }
  if (!is_option_set(test_quiet))
    printf("Failed! Got %08X%08X\n", (uint32_t)(value >> 32), (uint32_t)value);
  return true;
}

bool verify(const char *title, uint64_t (*hash)(const void *, size_t, uint64_t),
            const uint64_t *reference_values) {
  if (!is_option_set(test_quiet))
    printf("Testing %s...%s", title, is_option_set(test_verbose) ? "\n" : "");

  const uint64_t zero = 0;
  bool failed = false;
  failed |= probe(hash, "empty-zero", *reference_values++, NULL, 0, zero);
  failed |= probe(hash, "empty-all1", *reference_values++, NULL, 0, ~zero);
  failed |= probe(hash, "bin64-zero", *reference_values++, pattern, 64, zero);

  char caption[32];
  uint64_t seed = 1;
  for (int i = 1; i < 64; i++) {
    snprintf(caption, sizeof(caption), "bin%02i-1p%02u", i, i & 63);
    failed |= probe(hash, caption, *reference_values++, pattern, i, seed);
    seed <<= 1;
  }

  seed = ~zero;
  for (int i = 1; i <= 7; i++) {
    seed <<= 1;
    snprintf(caption, sizeof(caption), "align%i_F%u", i, 64 - i);
    failed |=
        probe(hash, caption, *reference_values++, pattern + i, 64 - i, seed);
  }

  uint8_t pattern_long[512];
  for (size_t i = 0; i < sizeof(pattern_long); ++i)
    pattern_long[i] = (uint8_t)i;
  for (int i = 0; i <= 7; i++) {
    snprintf(caption, sizeof(caption), "long-%05u", 128 + i * 17);
    failed |= probe(hash, caption, *reference_values++, pattern_long + i,
                    128 + i * 17, seed);
  }

  if (!is_option_set(test_quiet))
    printf(" %s\n", (!is_option_set(test_verbose) && !failed) ? "Ok" : "");
  return failed;
}
