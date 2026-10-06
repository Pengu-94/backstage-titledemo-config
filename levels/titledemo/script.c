/********************************************************************************
						Ultra 64 MARIO Brothers

						stage 25 sequence module

			Copyright 1995 Nintendo co., ltd.  All rights reserved

							December 8, 1995
 ********************************************************************************/

#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/group0.h"
#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/titledemo/header.h"

const LevelScript level_titledemo_entry[] = {

    INIT_LEVEL(),
    LOAD_MIO0(         /*seg*/ 0x07, _titledemo_segment_7SegmentRomStart, _titledemo_segment_7SegmentRomEnd),

    ALLOC_LEVEL_POOL(),

    LOAD_MODEL_FROM_GEO(MODEL_MARIO,   RCP_TitleMario),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,   RCP_TitleDemo25_Board),

    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),

    AREA(/*index*/ 1, RCP_TitleDemo25Scene1),

        OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ 0, -29, -74, /*angle*/ 0, 0, 0, /*behParam*/ 0x0, /*beh*/ bhvStaticObject),

        TERRAIN(/*terrainData*/ titledemo25_info),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_SOUND_PLAYER),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_GRASS),

    END_AREA(),

    FREE_LEVEL_POOL(),

    MARIO_POS(/*area*/ 1, /*yaw*/ 0, /*pos*/ 0, -29, -148),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
