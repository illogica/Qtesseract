#ifndef ENUMS_H
#define ENUMS_H

// ET_*: the only static entity types dictated by the engine... rest are gamecode dependent
enum StaticEntities{
    ET_EMPTY=0,
    ET_LIGHT,
    ET_MAPMODEL,
    ET_PLAYERSTART,
    ET_ENVMAP,
    ET_PARTICLES,
    ET_SOUND,
    ET_SPOTLIGHT,
    ET_DECAL,
    ET_GAMESPECIFIC
};

enum
{
    EF_NOVIS      = 1<<0,
    EF_NOSHADOW   = 1<<1,
    EF_NOCOLLIDE  = 1<<2,
    EF_ANIM       = 1<<3,
    EF_SHADOWMESH = 1<<4,
    EF_OCTA       = 1<<5,
    EF_RENDER     = 1<<6,
    EF_SOUND      = 1<<7,
    EF_SPAWNED    = 1<<8

};

enum ClientState{ CS_ALIVE = 0, CS_DEAD, CS_SPAWNING, CS_LAGGED, CS_EDITING, CS_SPECTATOR };

enum PhysicalState{ PHYS_FLOAT = 0, PHYS_FALL, PHYS_SLIDE, PHYS_SLOPE, PHYS_FLOOR, PHYS_STEP_UP, PHYS_STEP_DOWN, PHYS_BOUNCE };

enum { ENT_PLAYER = 0, ENT_CAMERA, ENT_BOUNCE };

enum { COLLIDE_NONE = 0, COLLIDE_ELLIPSE, COLLIDE_OBB, COLLIDE_TRI };

enum
{
    ANIM_MAPMODEL = 0,
    ANIM_GAMESPECIFIC
};

// animations
enum Animations
{
    ANIM_DEAD = ANIM_GAMESPECIFIC, ANIM_DYING,
    ANIM_IDLE, ANIM_RUN_N, ANIM_RUN_NE, ANIM_RUN_E, ANIM_RUN_SE, ANIM_RUN_S, ANIM_RUN_SW, ANIM_RUN_W, ANIM_RUN_NW,
    ANIM_JUMP, ANIM_JUMP_N, ANIM_JUMP_NE, ANIM_JUMP_E, ANIM_JUMP_SE, ANIM_JUMP_S, ANIM_JUMP_SW, ANIM_JUMP_W, ANIM_JUMP_NW,
    ANIM_SINK, ANIM_SWIM,
    ANIM_CROUCH, ANIM_CROUCH_N, ANIM_CROUCH_NE, ANIM_CROUCH_E, ANIM_CROUCH_SE, ANIM_CROUCH_S, ANIM_CROUCH_SW, ANIM_CROUCH_W, ANIM_CROUCH_NW,
    ANIM_CROUCH_JUMP, ANIM_CROUCH_JUMP_N, ANIM_CROUCH_JUMP_NE, ANIM_CROUCH_JUMP_E, ANIM_CROUCH_JUMP_SE, ANIM_CROUCH_JUMP_S, ANIM_CROUCH_JUMP_SW, ANIM_CROUCH_JUMP_W, ANIM_CROUCH_JUMP_NW,
    ANIM_CROUCH_SINK, ANIM_CROUCH_SWIM,
    ANIM_SHOOT, ANIM_MELEE,
    ANIM_PAIN,
    ANIM_EDIT, ANIM_LAG, ANIM_TAUNT, ANIM_WIN, ANIM_LOSE,
    ANIM_GUN_IDLE, ANIM_GUN_SHOOT, ANIM_GUN_MELEE,
    ANIM_VWEP_IDLE, ANIM_VWEP_SHOOT, ANIM_VWEP_MELEE,
    NUMANIMS
};

// console message types
enum Console
{
    CON_CHAT       = 1<<8,
    CON_TEAMCHAT   = 1<<9,
    CON_GAMEINFO   = 1<<10,
    CON_FRAG_SELF  = 1<<11,
    CON_FRAG_OTHER = 1<<12,
    CON_TEAMKILL   = 1<<13
};

enum Entities                           // static entity types
{
    NOTUSED = ET_EMPTY,         // entity slot not in use in map
    LIGHT = ET_LIGHT,           // lightsource, attr1 = radius, attr2 = intensity
    MAPMODEL = ET_MAPMODEL,     // attr1 = idx, attr2 = yaw, attr3 = pitch, attr4 = roll, attr5 = scale
    PLAYERSTART,                // attr1 = angle, attr2 = team
    ENVMAP = ET_ENVMAP,         // attr1 = radius
    PARTICLES = ET_PARTICLES,
    MAPSOUND = ET_SOUND,
    SPOTLIGHT = ET_SPOTLIGHT,
    DECAL = ET_DECAL,
    TELEPORT,                   // attr1 = idx, attr2 = model, attr3 = tag
    TELEDEST,                   // attr1 = angle, attr2 = idx
    JUMPPAD,                    // attr1 = zpush, attr2 = ypush, attr3 = xpush
    FLAG,                       // attr1 = angle, attr2 = team
    MAXENTTYPES,

    I_FIRST = 0,
    I_LAST = -1
};

enum Weapons { GUN_RAIL = 0, GUN_PULSE, NUMGUNS };
enum Actions { ACT_IDLE = 0, ACT_SHOOT, ACT_MELEE, NUMACTS };
enum Attacks { ATK_RAIL_SHOOT = 0, ATK_RAIL_MELEE, ATK_PULSE_SHOOT, ATK_PULSE_MELEE, NUMATKS };

enum GameModes
{
    M_TEAM       = 1<<0,
    M_CTF        = 1<<1,
    M_OVERTIME   = 1<<2,
    M_EDIT       = 1<<3,
    M_DEMO       = 1<<4,
    M_LOCAL      = 1<<5,
    M_LOBBY      = 1<<6,
    M_RAIL       = 1<<7,
    M_PULSE      = 1<<8
};

// hardcoded sounds, defined in sounds.cfg
enum Sounds
{
    S_JUMP = 0, S_LAND,
    S_SPLASHIN, S_SPLASHOUT, S_BURN,
    S_ITEMSPAWN, S_TELEPORT, S_JUMPPAD,
    S_MELEE, S_PULSE1, S_PULSE2, S_PULSEEXPLODE, S_RAIL1, S_RAIL2,
    S_WEAPLOAD, S_NOAMMO, S_HIT,
    S_PAIN1, S_PAIN2, S_DIE1, S_DIE2,

    S_FLAGPICKUP,
    S_FLAGDROP,
    S_FLAGRETURN,
    S_FLAGSCORE,
    S_FLAGRESET,
    S_FLAGFAIL
};

enum MasterMode{ MM_AUTH = -1, MM_OPEN = 0, MM_VETO, MM_LOCKED, MM_PRIVATE, MM_PASSWORD, MM_START = MM_AUTH, MM_INVALID = MM_START - 1 };

// network messages codes, c2s, c2c, s2c

enum Privilege{ PRIV_NONE = 0, PRIV_MASTER, PRIV_AUTH, PRIV_ADMIN };

enum Network
{
    N_CONNECT = 0, N_SERVINFO, N_WELCOME, N_INITCLIENT, N_POS, N_TEXT, N_SOUND, N_CDIS,
    N_SHOOT, N_EXPLODE, N_SUICIDE,
    N_DIED, N_DAMAGE, N_HITPUSH, N_SHOTFX, N_EXPLODEFX,
    N_TRYSPAWN, N_SPAWNSTATE, N_SPAWN, N_FORCEDEATH,
    N_GUNSELECT, N_TAUNT,
    N_MAPCHANGE, N_MAPVOTE, N_TEAMINFO, N_ITEMSPAWN, N_ITEMPICKUP, N_ITEMACC, N_TELEPORT, N_JUMPPAD,
    N_PING, N_PONG, N_CLIENTPING,
    N_TIMEUP, N_FORCEINTERMISSION,
    N_SERVMSG, N_ITEMLIST, N_RESUME,
    N_EDITMODE, N_EDITENT, N_EDITF, N_EDITT, N_EDITM, N_FLIP, N_COPY, N_PASTE, N_ROTATE, N_REPLACE, N_DELCUBE, N_CALCLIGHT, N_REMIP, N_EDITVSLOT, N_UNDO, N_REDO, N_NEWMAP, N_GETMAP, N_SENDMAP, N_CLIPBOARD, N_EDITVAR,
    N_MASTERMODE, N_KICK, N_CLEARBANS, N_CURRENTMASTER, N_SPECTATOR, N_SETMASTER, N_SETTEAM,
    N_LISTDEMOS, N_SENDDEMOLIST, N_GETDEMO, N_SENDDEMO,
    N_DEMOPLAYBACK, N_RECORDDEMO, N_STOPDEMO, N_CLEARDEMOS,
    N_TAKEFLAG, N_RETURNFLAG, N_RESETFLAG, N_TRYDROPFLAG, N_DROPFLAG, N_SCOREFLAG, N_INITFLAGS,
    N_SAYTEAM,
    N_CLIENT,
    N_AUTHTRY, N_AUTHKICK, N_AUTHCHAL, N_AUTHANS, N_REQAUTH,
    N_PAUSEGAME, N_GAMESPEED,
    N_ADDBOT, N_DELBOT, N_INITAI, N_FROMAI, N_BOTLIMIT, N_BOTBALANCE,
    N_MAPCRC, N_CHECKMAPS,
    N_SWITCHNAME, N_SWITCHMODEL, N_SWITCHCOLOR, N_SWITCHTEAM,
    N_SERVCMD,
    N_DEMOPACKET,
    NUMMSG
};

enum
{
    HICON_RED_FLAG = 0,
    HICON_BLUE_FLAG,

    HICON_X       = 20,
    HICON_Y       = 1650,
    HICON_TEXTY   = 1644,
    HICON_STEP    = 490,
    HICON_SIZE    = 120,
    HICON_SPACE   = 40
};


#endif // ENUMS_H
