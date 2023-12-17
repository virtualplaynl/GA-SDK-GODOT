#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

#include "GameAnalytics.h"

static GameAnalytics* GAPtr = NULL;

void initialize_gameanalytics_module(ModuleInitializationLevel p_level)
{
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        ClassDB::register_class<GameAnalytics>();
        GAPtr = memnew(GameAnalytics);
        Engine::get_singleton()->register_singleton("GameAnalytics", GameAnalytics::get_singleton());
    }
}

void uninitialize_gameanalytics_module(ModuleInitializationLevel p_level)
{
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        memdelete(GAPtr);
    }
}

extern "C"
{
    // Initialization.
    GDExtensionBool GDE_EXPORT gameanalytics_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_gameanalytics_module);
        init_obj.register_terminator(uninitialize_gameanalytics_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }

    GDExtensionBool GDE_EXPORT _gameanalytics_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        return gameanalytics_library_init(p_get_proc_address, p_library, r_initialization);
    }
}