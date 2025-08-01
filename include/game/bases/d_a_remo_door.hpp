#pragma once
#include <game/bases/d_actor_state.hpp>
#include <game/bases/d_audio.hpp>
#include <game/bases/d_heap_allocator.hpp>
#include <game/mLib/m_3d.hpp>
#include <lib/nw4r/g3d/res_file.hpp>

/// @brief A door that can be opened by tilting the Wii Remote.
/// @ingroup bases
/// @unused
class daRemoDoor_c : public dActorState_c {
public:
    daRemoDoor_c() : mRes(nullptr) {} ///< @copydoc dActorState_c::dActorState_c
    ~daRemoDoor_c() {} ///< @copydoc dActorState_c::~dActorState_c

    virtual int create();
    virtual int execute();
    virtual int draw();

    void init(); ///< Initializes the resources for the actor.

    STATE_FUNC_DECLARE(daRemoDoor_c, OpenReady);
    STATE_FUNC_DECLARE(daRemoDoor_c, Open);
    STATE_FUNC_DECLARE(daRemoDoor_c, Close);

    dHeapAllocator_c mAllocator; ///< The allocator.
    nw4r::g3d::ResFile mRes; ///< The resource file.
    m3d::mdl_c mDoorModel; ///< The door model.

    static const int SOUND_CLOSE; ///< The sound effect played when the door is closed.
    static const int SOUND_OPEN; ///< The sound effect played when the door is opened.
};
