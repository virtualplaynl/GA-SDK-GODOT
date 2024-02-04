#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
# env.Append(CPPPATH=["src/"])

if env["platform"] == "macos" or env["platform"] == "windows" or env["platform"] == "linux":
    env.Append(CPPPATH=[
        'GA-SDK-CPP/source/dependencies/crossguid',
        'GA-SDK-CPP/source/dependencies/crypto',
        'GA-SDK-CPP/source/dependencies/curl/include',
        'GA-SDK-CPP/source/dependencies/curl/include/curl',
        'GA-SDK-CPP/source/dependencies/miniz',
        'GA-SDK-CPP/source/dependencies/openssl',
        'GA-SDK-CPP/source/dependencies/rapidjson',
        'GA-SDK-CPP/source/dependencies/sqlite',
        'GA-SDK-CPP/source/dependencies/stacktrace',
        'GA-SDK-CPP/source/dependencies/zf_log',
        'GA-SDK-CPP/source/gameanalytics'
    ])

if env["platform"] == "macos":
    env.Append(CPPDEFINES=['GUID_CFUUID'])
if env["platform"] == "windows":
    env.Append(CPPDEFINES=[
        'GUID_WINDOWS',
        'CURL_STATICLIB'])
    env.Append(CPPPATH=['GA-SDK-CPP/source/dependencies/stackwalker'])
    env.Append(CXXFLAGS=['/EHsc'])
    env.Append(LIBS=[
        'ws2_32.lib',
        'wldap32.lib',
        'advapi32.lib',
        'kernel32.lib',
        'comdlg32.lib',
        'crypt32.lib',
        'normaliz.lib'])
if env["platform"] == "linux":
    env.Append(CPPDEFINES=[
        'GUID_LIBUUID',
        'USE_LINUX',
        '_GLIBCXX_USE_NANOSLEEP'])
    env.Append(LIBPATH=['lib/linux/x86_64'])
    env.Append(LIBS=[
        'crypto',
        'curl',
        'ssl'])
elif env["platform"] == "ios":
    env.Append(CCFLAGS=[
        '-Ilib/ios/GameAnalytics.xcframework/ios-arm64/GameAnalytics.framework/Headers'
    ])
    env.Append(LINKFLAGS=[
        '-ObjC',
        '-Flib/ios'
        '-framework', 'AdSupport',
        '-framework', 'SystemConfiguration',
        '-framework', 'AppTrackingTransparency',
        '-framework', 'GameAnalytics',
        '-l', 'sqlite3',
        '-l', 'z'
    ])
elif env["platform"] == "windows":
    if env["arch"] == "x86_64":
        env.Append(LIBPATH=["lib/win64"])
        env.Append(LIBS=["GameAnalytics.dll"])
    elif env["arch"] == "x86_32":
        env.Append(LIBPATH=["lib/win32"])
        env.Append(LIBS=["GameAnalytics.dll"])

sources = [Glob('*.cpp')]

if env["platform"] == "macos" or env["platform"] == "windows" or env["platform"] == "linux":
    sources.append([
        Glob('GA-SDK-CPP/source/gameanalytics/*.cpp'),
        Glob('GA-SDK-CPP/source/dependencies/crossguid/*.cpp'),
        Glob('GA-SDK-CPP/source/dependencies/crypto/*.c*'),
        'GA-SDK-CPP/source/dependencies/miniz/miniz.c',
        'GA-SDK-CPP/source/dependencies/sqlite/sqlite3.c',
        'GA-SDK-CPP/source/dependencies/zf_log/zf_log.c'])
    env['STATIC_AND_SHARED_OBJECTS_ARE_THE_SAME'] = 1

if env["platform"] == "macos":
    sources.append([
        'GA-SDK-CPP/source/gameanalytics/GADeviceOSX.mm',
        'GA-SDK-CPP/source/dependencies/curl/lib/osx/libcurl.a',
        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/osx/libcrypto.a',
        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/osx/libssl.a',
        'GA-SDK-CPP/source/dependencies/stacktrace/stacktrace/call_stack_gcc.cpp'])
    library = env.SharedLibrary(
        "lib/libgameanalytics.{}.{}.framework/libgameanalytics.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    sources.append("ios/src/GameAnalyticsiOS.mm")
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "lib/libgameanalytics.{}.{}.simulator.a".format(
                env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "lib/libgameanalytics.{}.{}.a".format(
                env["platform"], env["target"]),
            source=sources,
        )
elif env["platform"] == "windows":
    sources.append(['GA-SDK-CPP/source/dependencies/stacktrace/stacktrace/call_stack_msvc.cpp',
                   'GA-SDK-CPP/source/dependencies/stackwalker/StackWalker.cpp'])
    if env["arch"] == "x86_64":
        sources.append(['GA-SDK-CPP/source/dependencies/curl/lib/win64/vc140_x64_release/libcurl.lib',
                       'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win64/vc140_x64_release/libcrypto.lib',
                       'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win64/vc140_x64_release/libeay32.lib',
                       'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win64/vc140_x64_release/libssl.lib',
                       'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win64/vc140_x64_release/ssleay32.lib'])
    else:
        sources.append(['GA-SDK-CPP/source/dependencies/curl/lib/win32/vc140_x86_release/libcurl.lib',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win32/vc140_x86_release/libcrypto.lib',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win32/vc140_x86_release/libeay32.lib',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win32/vc140_x86_release/libssl.lib',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/win32/vc140_x86_release/ssleay32.lib'])

    library = env.SharedLibrary(
        "lib/libgameanalytics{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
elif  env["platform"] == "linux":
    if env["arch"] == "x86_64":
        sources.append(['GA-SDK-CPP/source/dependencies/curl/lib/linux_x64/libcurl.a',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/linux_x64/libcrypto.a',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/linux_x64/libssl.a'])
    else:
        sources.append(['GA-SDK-CPP/source/dependencies/curl/lib/linux_x86/libcurl.a',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/linux_x86/libcrypto.a',
                        'GA-SDK-CPP/source/dependencies/openssl/1.1.1d/libs/linux_x86/libssl.a'])
    sources.append('GA-SDK-CPP/source/dependencies/stacktrace/stacktrace/call_stack_gcc.cpp')
    library = env.SharedLibrary(
        "lib/libgameanalytics{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
