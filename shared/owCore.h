#pragma once

#include "../owCore/common.h"

// Cryptography
#include "../owCore/ARC4.h"
#include "../owCore/BigNumber.h"
#include "../owCore/HMACSHA1.h"
#include "../owCore/OpenSSLCrypto.h"
#include "../owCore/SHA1.h"

// Ref manager Sync
#include "../owCore/RefItem.h"
#include "../owCore/SmartPtr.h"
#include "../owCore/UniquePtr.h"
#include "../owCore/RefManager1Dim.h"
#include "../owCore/RefManager1DimAssync.h"

// Files
#include "../owCore/MPQArchiveManager.h"
#include "../owCore/FilesManager.h"
#include "../owCore/File.h"
#include "../owCore/LocalFile.h"
#include "../owCore/MPQFile.h"
#include "../owCore/INIFile.h"
#include "../owCore/XMLFile.h"

#include "../owCore/DebugOutput.h"

// CLog outputs

#include "../owCore/Console.h"
#include "../owCore/Input.h"

// Objects bindings
#include "../owCore/BaseManager.h"
#include "../owCore/BindingController.h"
#include "../owCore/Settings.h"