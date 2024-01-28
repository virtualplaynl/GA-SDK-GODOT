#include "GodotGameAnalytics.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#define VERSION "godot 3.0.0"
#if defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
using namespace gameanalytics;
#endif

namespace godot
{
#if !defined(IOS_ENABLED)
    GodotRemoteConfigsListener::GodotRemoteConfigsListener(GodotGameAnalytics *_gaObject)
    {
        gaObject = _gaObject;
    }
    void GodotRemoteConfigsListener::onRemoteConfigsUpdated()
    {
        gaObject->onRemoteConfigsUpdated();
    }
#endif

    GodotGameAnalytics *GodotGameAnalytics::instance = NULL;

    GodotGameAnalytics::GodotGameAnalytics()
    {
        ERR_FAIL_COND(instance != NULL); //<< SUCCESS!!! FIRST
        instance = this;
    }

    GodotGameAnalytics *GodotGameAnalytics::get_singleton()
    {
        return instance;
    }

    GodotGameAnalytics::~GodotGameAnalytics()
    {
        if (instance == this)
        {
            instance = NULL;
        }
    }

    void GodotGameAnalytics::configureAvailableCustomDimensions01(const PackedStringArray &customDimensions)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAvailableCustomDimensions01(customDimensions);
#else
        String arrayString = "";
        if (customDimensions.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < customDimensions.size(); ++i)
            {
                String entry = customDimensions[i];
                if (i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
#if defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureAvailableCustomDimensions01(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureAvailableCustomDimensions01(arrayString.utf8().get_data());
#endif
#endif
    }

    void GodotGameAnalytics::configureAvailableCustomDimensions02(const PackedStringArray &customDimensions)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAvailableCustomDimensions02(customDimensions);
#else
        String arrayString = "";
        if (customDimensions.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < customDimensions.size(); ++i)
            {
                String entry = customDimensions[i];
                if (i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
#if defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureAvailableCustomDimensions02(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureAvailableCustomDimensions02(arrayString.utf8().get_data());
#endif
#endif
    }

    void GodotGameAnalytics::configureAvailableCustomDimensions03(const PackedStringArray &customDimensions)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAvailableCustomDimensions03(customDimensions);
#else
        String arrayString = "";
        if (customDimensions.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < customDimensions.size(); ++i)
            {
                String entry = customDimensions[i];
                if (i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
#if defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureAvailableCustomDimensions03(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        String arrayString = "";

        if(customDimensions.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < customDimensions.size(); ++i)
            {
                String entry = customDimensions[i];
                if(i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
        GameAnalytics::configureAvailableCustomDimensions03(arrayString.utf8().get_data());
#endif
#endif
    }

    void GodotGameAnalytics::configureAvailableResourceCurrencies(const PackedStringArray &resourceCurrencies)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAvailableResourceCurrencies(resourceCurrencies);
#else
        String arrayString = "";
        if (resourceCurrencies.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < resourceCurrencies.size(); ++i)
            {
                String entry = resourceCurrencies[i];
                if (i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
#if defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureAvailableResourceCurrencies(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureAvailableResourceCurrencies(arrayString.utf8().get_data());
#endif
#endif
    }

    void GodotGameAnalytics::configureAvailableResourceItemTypes(const PackedStringArray &resourceItemTypes)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAvailableResourceItemTypes(resourceItemTypes);
#else
        String arrayString = "";
        if (resourceItemTypes.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < resourceItemTypes.size(); ++i)
            {
                String entry = resourceItemTypes[i];
                if (i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
#if defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureAvailableResourceItemTypes(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        String arrayString = "";

        if(resourceItemTypes.size() > 0)
        {
            arrayString += "[\"";
            for (int i = 0; i < resourceItemTypes.size(); ++i)
            {
                String entry = resourceItemTypes[i];
                if(i > 0)
                {
                    arrayString += "\",\"";
                }
                arrayString += entry;
            }
            arrayString += "\"]";
        }
        else
        {
            arrayString = "[]";
        }
        GameAnalytics::configureAvailableResourceItemTypes(arrayString.utf8().get_data());
#endif
#endif
    }

    void GodotGameAnalytics::configureBuild(const String &build)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureBuild(build.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureBuild('" + build + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureBuild(build.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::configureAutoDetectAppVersion(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureAutoDetectAppVersion(flag);
#elif defined(WEB_PLATFORM)
        // TODO: add implementation
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        // Do nothing
#endif
    }

    void GodotGameAnalytics::configureUserId(const String &userId)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureUserId(userId.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureBuild('" + userId + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureUserId(userId.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::configureSdkGameEngineVersion(const String &version)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureSdkGameEngineVersion(version.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureSdkGameEngineVersion('" + version + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureSdkGameEngineVersion(version.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::configureGameEngineVersion(const String &version)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureGameEngineVersion(version.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.configureGameEngineVersion('" + version + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureGameEngineVersion(version.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::configureWritablePath(const String &writablePath)
    {
#if defined(IOS_PLATFORM)
        // Do nothing
#elif defined(WEB_PLATFORM)
        // Do nothing
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::configureWritablePath(writablePath.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::init(const String &gameKey, const String &secretKey)
    {
        Dictionary versionInfo = Engine::get_singleton()->get_version_info();
        String major = versionInfo.get("major", "x");
        String minor = versionInfo.get("minor", "x");
        String patch = versionInfo.get("patch", "x");
        String engineVersion = "godot " + major + "." + minor + "." + patch;
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::configureBuild(nullptr);
        GameAnalyticsiOS::configureGameEngineVersion(engineVersion.utf8().get_data());
        GameAnalyticsiOS::configureSdkGameEngineVersion(VERSION);
        GameAnalyticsiOS::initialize(gameKey.utf8().get_data(), secretKey.utf8().get_data());
#elif defined(WEB_PLATFORM)
        configureGameEngineVersion(engineVersion);
        configureSdkGameEngineVersion(VERSION);
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.initialize('%s', '%s')", gameKey, secretKey));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        logging::GALogger::setCustomLogHandler([](const char *message, EGALoggerMessageType messageType) {
            if(messageType == EGALoggerMessageType::LogDebug || messageType == EGALoggerMessageType::LogInfo)
                UtilityFunctions::print(message);
            else
                UtilityFunctions::printerr(message);
        });
        GameAnalytics::addRemoteConfigsListener(std::shared_ptr<IRemoteConfigsListener>((IRemoteConfigsListener *)new GodotRemoteConfigsListener(this)));
        GameAnalytics::configureGameEngineVersion(engineVersion.utf8().get_data());
        GameAnalytics::configureSdkGameEngineVersion(VERSION);
        GameAnalytics::initialize(gameKey.utf8().get_data(), secretKey.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::addBusinessEvent(const Dictionary &options)
    {
        String currency = "";
        int amount = 0;
        String itemType = "";
        String itemId = "";
        String cartType = "";
        String receipt = "";
        bool autoFetchReceipt = false;
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "currency")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    currency = v;
                }
            }
            else if(key == "amount")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::INT)
                {
                    amount = v;
                }
            }
            else if(key == "itemType")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    itemType = v;
                }
            }
            else if(key == "itemId")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    itemId = v;
                }
            }
            else if(key == "cartType")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    cartType = v;
                }
            }
            else if(key == "receipt")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    receipt = v;
                }
            }
            else if(key == "autoFetchReceipt")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    autoFetchReceipt = v;
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        if(autoFetchReceipt)
        {
            GameAnalyticsiOS::addBusinessEventAndAutoFetchReceipt(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
        else
        {
            GameAnalyticsiOS::addBusinessEvent(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), receipt.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
#elif defined(WEB_PLATFORM)
        String lastPart = vformat("'%s', JSON.parse('%s'), %s", cartType, fields, mergeFields ? "true" : "false");
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addBusinessEvent('%s', %d, '%s', '%s', %s)", currency, amount, itemType, itemId, lastPart));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::addBusinessEvent(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), fields.utf8().get_data(), mergeFields);
#endif
    }

    void GodotGameAnalytics::addResourceEvent(const Dictionary &options)
    {
        int flowType = 0;
        String currency = "";
        float amount = 0;
        String itemType = "";
        String itemId = "";
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "flowType")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if(s == "Source")
                    {
                        flowType = 1;
                    }
                    else if(s == "Sink")
                    {
                        flowType = 2;
                    }
                }
            }
            else if(key == "currency")
            {
                const Variant v = options.get(key, strnull);
                if (v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    currency = v;
                }
            }
            else if(key == "amount")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && (v.get_type() == Variant::Type::INT || v.get_type() == Variant::Type::FLOAT))
                {
                    amount = v;
                }
            }
            else if(key == "itemType")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    itemType = v;
                }
            }
            else if(key == "itemId")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    itemId = v;
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::addResourceEvent(flowType, currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), fields.utf8().get_data(), mergeFields);
#elif defined(WEB_PLATFORM)
        String lastPart = vformat("'%s', JSON.parse('%s'), %s", itemId, fields, mergeFields ? "true" : "false");
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addResourceEvent(%d, '%s', %f, '%s', %s)", flowType, currency, amount, itemType, lastPart));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::addResourceEvent((EGAResourceFlowType)flowType, currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), fields.utf8().get_data(), mergeFields);
#endif
    }

    void GodotGameAnalytics::addProgressionEvent(const Dictionary &options)
    {
        int progressionStatus = 0;
        String progression01 = "";
        String progression02 = "";
        String progression03 = "";
        int score = 0;
        bool sendScore = false;
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "progressionStatus")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if(s == "Start")
                    {
                        progressionStatus = 1;
                    }
                    else if(s == "Complete")
                    {
                        progressionStatus = 2;
                    }
                    else if(s == "Fail")
                    {
                        progressionStatus = 3;
                    }
                }
            }
            else if(key == "progression01")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    progression01 = v;
                }
            }
            else if(key == "progression02")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    progression02 = v;
                }
            }
            else if(key == "progression03")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    progression03 = v;
                }
            }
            else if(key == "score")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::INT)
                {
                    score = v;
                    sendScore = true;
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        if(sendScore)
        {
            GameAnalyticsiOS::addProgressionEventWithScore(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), score, fields.utf8().get_data(), mergeFields);
        }
        else
        {
            GameAnalyticsiOS::addProgressionEvent(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
#elif defined(WEB_PLATFORM)
        if (sendScore)
        {
            String lastPart = vformat("%d, JSON.parse('%s'), %s", score, fields, mergeFields ? "true" : "false");
            JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addProgressionEvent(%d, '%s', '%s', '%s', %s)", progressionStatus, progression01, progression02, progression03, lastPart));
        }
        else
        {
            String lastPart = vformat("JSON.parse('%s'), %s", fields, mergeFields ? "true" : "false");
            JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addProgressionEvent(%d, '%s', '%s', '%s', %s)", progressionStatus, progression01, progression02, progression03, lastPart));
        }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        if(sendScore)
        {
            GameAnalytics::addProgressionEvent((EGAProgressionStatus)progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), score, fields.utf8().get_data(), mergeFields);
        }
        else
        {
            GameAnalytics::addProgressionEvent((EGAProgressionStatus)progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
#endif
    }

    void GodotGameAnalytics::addDesignEvent(const Dictionary &options)
    {
        String eventId = "";
        float value = 0;
        bool sendValue = false;
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "eventId")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    eventId = v;
                }
            }
            else if(key == "value")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && (v.get_type() == Variant::Type::INT || v.get_type() == Variant::Type::FLOAT))
                {
                    value = v;
                    sendValue = true;
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        if(sendValue)
        {
            GameAnalyticsiOS::addDesignEventWithValue(eventId.utf8().get_data(), value, fields.utf8().get_data(), mergeFields);
        }
        else
        {
            GameAnalyticsiOS::addDesignEvent(eventId.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
#elif defined(WEB_PLATFORM)
        if (sendValue)
        {
            JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addDesignEvent('%s', %f, JSON.parse('%s'), %s)", eventId, value, fields, mergeFields ? "true" : "false"));
        }
        else
        {
            JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addDesignEvent('%s', JSON.parse('%s'), %s)", eventId, fields, mergeFields ? "true" : "false"));
        }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        if(sendValue)
        {
            GameAnalytics::addDesignEvent(eventId.utf8().get_data(), value, fields.utf8().get_data(), mergeFields);
        }
        else
        {
            GameAnalytics::addDesignEvent(eventId.utf8().get_data(), fields.utf8().get_data(), mergeFields);
        }
#endif
    }

    void GodotGameAnalytics::addErrorEvent(const Dictionary &options)
    {
        int severity = 0;
        String message = "";
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "severity")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if(s == "Debug")
                    {
                        severity = 1;
                    }
                    else if(s == "Info")
                    {
                        severity = 2;
                    }
                    else if(s == "Warning")
                    {
                        severity = 3;
                    }
                    else if(s == "Error")
                    {
                        severity = 4;
                    }
                    else if(s == "Critical")
                    {
                        severity = 5;
                    }
                }
            }
            else if(key == "message")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    message = v;
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::addErrorEvent(severity, message.utf8().get_data(), fields.utf8().get_data(), mergeFields);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.addErrorEvent(%d, '%s', JSON.parse('%s'), %s)", severity, message, fields, mergeFields ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::addErrorEvent((EGAErrorSeverity)severity, message.utf8().get_data(), fields.utf8().get_data(), mergeFields);
#endif
    }

    void GodotGameAnalytics::addAdEvent(const Dictionary &options)
    {
        int adAction = 0;
        int adType = 0;
        int noAdReason = 0;
        String adSdkName = "";
        String adPlacement = "";
        bool sendDuration = false;
        int duration = -1;
        String fields = "{}";
        bool mergeFields = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if (key == "adAction")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if (s == "Clicked")
                    {
                        adAction = 1;
                    }
                    else if (s == "Show")
                    {
                        adAction = 2;
                    }
                    else if (s == "FailedShow")
                    {
                        adAction = 3;
                    }
                    else if (s == "RewardReceived")
                    {
                        adAction = 4;
                    }
                }
            }
            else if (key == "adType")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if (s == "Video")
                    {
                        adType = 1;
                    }
                    else if (s == "RewardedVideo")
                    {
                        adType = 2;
                    }
                    else if (s == "Playable")
                    {
                        adType = 3;
                    }
                    else if (s == "Interstitial")
                    {
                        adType = 4;
                    }
                    else if (s == "OfferWall")
                    {
                        adType = 5;
                    }
                    else if (s == "Banner")
                    {
                        adType = 6;
                    }
                }
            }
            else if (key == "adSdkName")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    adSdkName = v;
                }
            }
            else if (key == "adPlacement")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    adPlacement = v;
                }
            }
            else if (key == "duration")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::INT)
                {
                    duration = v;
                    sendDuration = true;
                }
            }
            else if (key == "noAdReason")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    String s = v;
                    if (s == "Unknown")
                    {
                        noAdReason = 1;
                    }
                    else if (s == "Offline")
                    {
                        noAdReason = 2;
                    }
                    else if (s == "NoFill")
                    {
                        noAdReason = 3;
                    }
                    else if (s == "InternalError")
                    {
                        noAdReason = 4;
                    }
                    else if (s == "InvalidRequest")
                    {
                        noAdReason = 5;
                    }
                    else if (s == "UnableToPrecache")
                    {
                        noAdReason = 6;
                    }
                }
            }
            else if (key == "customFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    fields = v;
                }
            }
            else if (key == "mergeFields")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::BOOL)
                {
                    mergeFields = v;
                }
            }
        }
#if defined(IOS_PLATFORM)
        if(sendDuration)
        {
            GameAnalyticsiOS::addAdEventWithDuration(adAction, adType, adSdkName.utf8().ptr(), adPlacement.utf8().ptr(), duration, fields.utf8().ptr(), mergeFields);
        }
        else
        {
            GameAnalyticsiOS::addAdEventWithNoAdReason(adAction, adType, adSdkName.utf8().ptr(), adPlacement.utf8().ptr(), noAdReason, fields.utf8().ptr(), mergeFields);
        }
#elif defined(WEB_PLATFORM)
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
#endif
    }

    void GodotGameAnalytics::setEnabledInfoLog(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setEnabledInfoLog(flag);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setEnabledInfoLog(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setEnabledInfoLog(flag);
#endif
    }

    void GodotGameAnalytics::setEnabledVerboseLog(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setEnabledVerboseLog(flag);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setEnabledVerboseLog(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setEnabledVerboseLog(flag);
#endif
    }

    void GodotGameAnalytics::setEnabledManualSessionHandling(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setEnabledManualSessionHandling(flag);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setEnabledManualSessionHandling(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setEnabledManualSessionHandling(flag);
#endif
    }

    void GodotGameAnalytics::setEnabledErrorReporting(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setEnabledErrorReporting(flag);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setEnabledErrorReporting(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setEnabledErrorReporting(flag);
#endif
    }

    void GodotGameAnalytics::setEnabledEventSubmission(bool flag)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setEnabledEventSubmission(flag);
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setEnabledEventSubmission(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setEnabledEventSubmission(flag);
#endif
    }

    void GodotGameAnalytics::setCustomDimension01(const String &dimension)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setCustomDimension01(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setCustomDimension01('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setCustomDimension01(dimension.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::setCustomDimension02(const String &dimension)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setCustomDimension02(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setCustomDimension02('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setCustomDimension02(dimension.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::setCustomDimension03(const String &dimension)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setCustomDimension03(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setCustomDimension03('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setCustomDimension03(dimension.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::setGlobalCustomEventFields(const String &customFields)
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::setGlobalCustomEventFields(customFields.utf8().get_data());
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.setGlobalCustomEventFields(JSON.parse('%s'))", !customFields.empty() ? customFields : "{}"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::setGlobalCustomEventFields(customFields.utf8().get_data());
#endif
    }

    void GodotGameAnalytics::startSession()
    {
#if defined(IOS_PLATFORM)
        GameAnalyticsiOS::startSession();
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.startSession()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::startSession();
#endif
    }

    void GodotGameAnalytics::endSession()
    {
    #if defined(IOS_PLATFORM)
        GameAnalyticsiOS::endSession();
    #elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.endSession()");
    #elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::endSession();
#endif
    }

    void GodotGameAnalytics::onQuit()
    {
#if defined(IOS_PLATFORM)
        // Do nothing
#elif defined(WEB_PLATFORM)
        // Do nothing
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::onQuit();
#endif
    }

    void GodotGameAnalytics::onResume()
    {
#if defined(IOS_PLATFORM)
        // Do nothing
#elif defined(WEB_PLATFORM)
        // Do nothing
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::onResume();
#endif
    }

    void GodotGameAnalytics::onSuspend()
    {
#if defined(IOS_PLATFORM)
        // Do nothing
#elif defined(WEB_PLATFORM)
        // Do nothing
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::onSuspend();
#endif
    }

    void GodotGameAnalytics::disableDeviceInfo()
    {
#if defined(IOS_PLATFORM)
        // Do nothing
#elif defined(WEB_PLATFORM)
        JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.disableDeviceInfo()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        GameAnalytics::disableDeviceInfo();
#endif
    }

    bool GodotGameAnalytics::isThreadEnding()
    {
#if defined(IOS_PLATFORM)
        return false;
#elif defined(WEB_PLATFORM)
        return JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.isThreadEnding()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        return GameAnalytics::isThreadEnding();
#endif
    }


    String GodotGameAnalytics::getRemoteConfigsValueAsString(const Dictionary &options)
    {
        String k = "";
        String defaultValue = "";
        bool useDefaultValue = false;

        const String strnull = String((char *)NULL);

        Array keys = options.keys();
        for (int i = 0; i < keys.size(); ++i)
        {
            String key = keys[i];

            if(key == "key")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    k = v;
                }
            }
            else if(key == "defaultValue")
            {
                const Variant v = options.get(key, strnull);
                if(v != strnull && v.get_type() == Variant::Type::STRING)
                {
                    defaultValue = v;
                    useDefaultValue = true;
                }
            }
        }
#if defined(IOS_PLATFORM)
        if(useDefaultValue)
        {
            return GameAnalyticsiOS::getRemoteConfigsValueAsString(k.utf8().get_data(), defaultValue.utf8().get_data());
        }
        else
        {
            return GameAnalyticsiOS::getRemoteConfigsValueAsString(k.utf8().get_data());
        }
#elif defined(WEB_PLATFORM)
        if (useDefaultValue)
        {
            return String(JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.getRemoteConfigsValueAsString('%s', '%s')", k, defaultValue)));
        }
        else
        {
            return String(JavaScript::get_singleton()->eval(vformat("gameanalytics.GodotGameAnalytics.getRemoteConfigsValueAsString('%s')", k)));
        }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        std::vector<char> result;
        if (useDefaultValue)
        {
            result = GameAnalytics::getRemoteConfigsValueAsString(k.utf8().get_data(), defaultValue.utf8().get_data());
        }
        else
        {
            result = GameAnalytics::getRemoteConfigsValueAsString(k.utf8().get_data());
        }
        return String(std::string(result.begin(), result.end()).c_str());
#endif
    }

    bool GodotGameAnalytics::isRemoteConfigsReady()
    {
    #if defined(IOS_PLATFORM)
        return GameAnalyticsiOS::isRemoteConfigsReady();
    #elif defined(WEB_PLATFORM)
        return JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.isRemoteConfigsReady()");
    #elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        return GameAnalytics::isRemoteConfigsReady();
#endif
    }

    String GodotGameAnalytics::getRemoteConfigsContentAsString()
    {
#if defined(IOS_PLATFORM)
        return GameAnalyticsiOS::getRemoteConfigsContentAsString();
#elif defined(WEB_PLATFORM)
        return String(JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.getRemoteConfigsContentAsString()"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        std::vector<char> result = GameAnalytics::getRemoteConfigsContentAsString();
        return String(std::string(result.begin(), result.end()).c_str());
#endif
    }

    void GodotGameAnalytics::onRemoteConfigsUpdated()
    {
        emit_signal(SignalNameRemoteConfigsUpdated);
    }

    String GodotGameAnalytics::getABTestingId()
    {
#if defined(IOS_PLATFORM)
        return GameAnalyticsiOS::getABTestingId();
#elif defined(WEB_PLATFORM)
        return String(JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.getABTestingId()"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        std::vector<char> result = GameAnalytics::getABTestingId();
        return String(std::string(result.begin(), result.end()).c_str());
#endif
    }

    String GodotGameAnalytics::getABTestingVariantId()
    {
#if defined(IOS_PLATFORM)
        return GameAnalyticsiOS::getABTestingVariantId();
#elif defined(WEB_PLATFORM)
        return String(JavaScript::get_singleton()->eval("gameanalytics.GodotGameAnalytics.getABTestingVariantId()"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
        std::vector<char> result = GameAnalytics::getABTestingVariantId();
        return String(std::string(result.begin(), result.end()).c_str());
#endif
    }

    void GodotGameAnalytics::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("configure_available_custom_dimensions01", "custom_dimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions01);
        ClassDB::bind_method(D_METHOD("configure_available_custom_dimensions02", "custom_dimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions02);
        ClassDB::bind_method(D_METHOD("configure_available_custom_dimensions03", "custom_dimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions03);

        ClassDB::bind_method(D_METHOD("configure_available_resource_currencies", "resource_currencies"), &GodotGameAnalytics::configureAvailableResourceCurrencies);
        ClassDB::bind_method(D_METHOD("configure_available_resource_item_types", "resource_item_types"), &GodotGameAnalytics::configureAvailableResourceItemTypes);

        ClassDB::bind_method(D_METHOD("configure_build", "build"), &GodotGameAnalytics::configureBuild);
        ClassDB::bind_method(D_METHOD("configure_auto_detect_app_version", "flag"), &GodotGameAnalytics::configureAutoDetectAppVersion);
        ClassDB::bind_method(D_METHOD("configure_user_id", "user_id"), &GodotGameAnalytics::configureUserId);
        void configureSdkGameEngineVersion(const String &version);
        void configureGameEngineVersion(const String &version);
        void configureWritablePath(const String &writablePath);

        ClassDB::bind_method(D_METHOD("init", "game_key", "secret_key"), &GodotGameAnalytics::init);

        ClassDB::bind_method(D_METHOD("add_business_event", "options"), &GodotGameAnalytics::addBusinessEvent);
        ClassDB::bind_method(D_METHOD("add_resource_event", "options"), &GodotGameAnalytics::addResourceEvent);
        ClassDB::bind_method(D_METHOD("add_progression_event", "options"), &GodotGameAnalytics::addProgressionEvent);
        ClassDB::bind_method(D_METHOD("add_design_event", "options"), &GodotGameAnalytics::addDesignEvent);
        ClassDB::bind_method(D_METHOD("add_error_event", "options"), &GodotGameAnalytics::addErrorEvent);
        ClassDB::bind_method(D_METHOD("add_ad_event", "options"), &GodotGameAnalytics::addAdEvent);

        ClassDB::bind_method(D_METHOD("set_enabled_info_log", "flag"), &GodotGameAnalytics::setEnabledInfoLog);
        ClassDB::bind_method(D_METHOD("set_enabled_verbose_log", "flag"), &GodotGameAnalytics::setEnabledVerboseLog);
        ClassDB::bind_method(D_METHOD("set_enabled_manual_session_handling", "flag"), &GodotGameAnalytics::setEnabledManualSessionHandling);
        ClassDB::bind_method(D_METHOD("set_enabled_error_reporting", "flag"), &GodotGameAnalytics::setEnabledErrorReporting);
        ClassDB::bind_method(D_METHOD("set_enabled_event_submission", "flag"), &GodotGameAnalytics::setEnabledEventSubmission);

        ClassDB::bind_method(D_METHOD("set_custom_dimension01", "dimension"), &GodotGameAnalytics::setCustomDimension01);
        ClassDB::bind_method(D_METHOD("set_custom_dimension02", "dimension"), &GodotGameAnalytics::setCustomDimension02);
        ClassDB::bind_method(D_METHOD("set_custom_dimension03", "dimension"), &GodotGameAnalytics::setCustomDimension03);

        ClassDB::bind_method(D_METHOD("set_global_custom_event_fields", "custom_fields"), &GodotGameAnalytics::setGlobalCustomEventFields);

        ClassDB::bind_method(D_METHOD("start_session"), &GodotGameAnalytics::startSession);
        ClassDB::bind_method(D_METHOD("end_session"), &GodotGameAnalytics::endSession);
        ClassDB::bind_method(D_METHOD("on_quit"), &GodotGameAnalytics::onQuit);
        ClassDB::bind_method(D_METHOD("on_resume"), &GodotGameAnalytics::onResume);
        ClassDB::bind_method(D_METHOD("on_suspend"), &GodotGameAnalytics::onSuspend);

        ClassDB::bind_method(D_METHOD("disable_device_info"), &GodotGameAnalytics::disableDeviceInfo);
        ClassDB::bind_method(D_METHOD("is_thread_ending"), &GodotGameAnalytics::isThreadEnding);

        ClassDB::bind_method(D_METHOD("get_remote_configs_value_as_string", "options"), &GodotGameAnalytics::getRemoteConfigsValueAsString);
        ClassDB::bind_method(D_METHOD("is_remote_configs_ready"), &GodotGameAnalytics::isRemoteConfigsReady);
        ClassDB::bind_method(D_METHOD("get_remote_configs_content_as_string"), &GodotGameAnalytics::getRemoteConfigsContentAsString);

        ClassDB::bind_method(D_METHOD("get_ab_testing_id"), &GodotGameAnalytics::getABTestingId);
        ClassDB::bind_method(D_METHOD("get_ab_testing_variant_id"), &GodotGameAnalytics::getABTestingVariantId);

        /*** Old bindings, enable for backward compatibility in GDScript
        ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions01", "customDimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions01);
        ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions02", "customDimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions02);
        ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions03", "customDimensions"), &GodotGameAnalytics::configureAvailableCustomDimensions03);

        ClassDB::bind_method(D_METHOD("configureAvailableResourceCurrencies", "resourceCurrencies"), &GodotGameAnalytics::configureAvailableResourceCurrencies);
        ClassDB::bind_method(D_METHOD("configureAvailableResourceItemTypes", "resourceItemTypes"), &GodotGameAnalytics::configureAvailableResourceItemTypes);

        ClassDB::bind_method(D_METHOD("configureBuild", "build"), &GodotGameAnalytics::configureBuild);
        ClassDB::bind_method(D_METHOD("configureAutoDetectAppVersion", "flag"), &GodotGameAnalytics::configureAutoDetectAppVersion);
        ClassDB::bind_method(D_METHOD("configureUserId", "userId"), &GodotGameAnalytics::configureUserId);

        ClassDB::bind_method(D_METHOD("init", "gameKey", "secretKey"), &GodotGameAnalytics::init);

        ClassDB::bind_method(D_METHOD("addBusinessEvent", "options"), &GodotGameAnalytics::addBusinessEvent);
        ClassDB::bind_method(D_METHOD("addResourceEvent", "options"), &GodotGameAnalytics::addResourceEvent);
        ClassDB::bind_method(D_METHOD("addProgressionEvent", "options"), &GodotGameAnalytics::addProgressionEvent);
        ClassDB::bind_method(D_METHOD("addDesignEvent", "options"), &GodotGameAnalytics::addDesignEvent);
        ClassDB::bind_method(D_METHOD("addErrorEvent", "options"), &GodotGameAnalytics::addErrorEvent);
        ClassDB::bind_method(D_METHOD("addAdEvent", "options"), &GodotGameAnalytics::addAdEvent);

        ClassDB::bind_method(D_METHOD("setEnabledInfoLog", "flag"), &GodotGameAnalytics::setEnabledInfoLog);
        ClassDB::bind_method(D_METHOD("setEnabledVerboseLog", "flag"), &GodotGameAnalytics::setEnabledVerboseLog);
        ClassDB::bind_method(D_METHOD("setEnabledManualSessionHandling", "flag"), &GodotGameAnalytics::setEnabledManualSessionHandling);
        ClassDB::bind_method(D_METHOD("setEnabledErrorReporting", "flag"), &GodotGameAnalytics::setEnabledErrorReporting);
        ClassDB::bind_method(D_METHOD("setEnabledEventSubmission", "flag"), &GodotGameAnalytics::setEnabledEventSubmission);

        ClassDB::bind_method(D_METHOD("setCustomDimension01", "dimension"), &GodotGameAnalytics::setCustomDimension01);
        ClassDB::bind_method(D_METHOD("setCustomDimension02", "dimension"), &GodotGameAnalytics::setCustomDimension02);
        ClassDB::bind_method(D_METHOD("setCustomDimension03", "dimension"), &GodotGameAnalytics::setCustomDimension03);

        ClassDB::bind_method(D_METHOD("setGlobalCustomEventFields", "customFields"), &GodotGameAnalytics::setGlobalCustomEventFields);

        ClassDB::bind_method(D_METHOD("startSession"), &GodotGameAnalytics::startSession);
        ClassDB::bind_method(D_METHOD("endSession"), &GodotGameAnalytics::endSession);
        ClassDB::bind_method(D_METHOD("onQuit"), &GodotGameAnalytics::onQuit);

        ClassDB::bind_method(D_METHOD("getRemoteConfigsValueAsString", "options"), &GodotGameAnalytics::getRemoteConfigsValueAsString);
        ClassDB::bind_method(D_METHOD("isRemoteConfigsReady"), &GodotGameAnalytics::isRemoteConfigsReady);
        ClassDB::bind_method(D_METHOD("getRemoteConfigsContentAsString"), &GodotGameAnalytics::getRemoteConfigsContentAsString);
        ***/
    }
}