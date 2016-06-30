
function startup() {
    console.log("JS startup" + Events.N_WELCOME + " hey hey hey!");
}

server.registerHook(Events.N_CONNECT, "onConnect");
server.registerHook(Events.N_POS, "onPos");
server.registerHook(Events.N_TEXT, "onText");
server.registerHook(Events.N_TELEPORT, "onTeleport");
server.registerHook(Events.N_JUMPPAD, "onJumppad");
server.registerHook(Events.N_FROMAI, "onFromai");
server.registerHook(Events.N_MAPCRC, "onMapcrc");
server.registerHook(Events.N_CHECKMAPS, "onCheckmaps");
server.registerHook(Events.N_EDITMODE, "onEditmode");
server.registerHook(Events.N_TRYSPAWN, "onTryspawn");
server.registerHook(Events.N_GUNSELECT, "onGunselect");
server.registerHook(Events.N_SPAWN, "onSpawn");
server.registerHook(Events.N_SUICIDE, "onSuicide");
server.registerHook(Events.N_SHOOT, "onShoot");

function onConnect(ci, password, authdesc, authname, sender, chan, eventdata){
    var disconnect = server.allowconnect(ci, password);

    if(disconnect !== Disconnect.DISC_NONE){
        var sauth = server.serverauth();
        if(disconnect === Disconnect.DISC_LOCAL || sauth === "" || sauth === authdesc){
            server.disconnect_client(sender, disconnect);
            return;
        } else {
            ci.connectauth = disconnect;
        }
    } else {
        server.connected(ci);
    }
    server.sendservmsg("disconnect = " + disconnect);
    server.sendservmsg("client " + ci.name + " connected.");

    eventdata.bypass = true; //or the server will segfault
}

function onPos(ci, cp, pcn, posx, posy, posz, velx, vely, velz, sender, eventdata){
    var pos = new Vec(posx, posy, posz);
    var vel = new Vec(velx, vely, velz);

    //note: make sure a clientinfo is !== null
    var msg = "";
    if(cp !== null)
        msg += "cp.name: " + cp.name + " ";
    msg += "pcn: " + pcn + " ";
    msg += "pos: " + pos.length().toFixed(1) + " ";
    msg += "vel:" + vel.length().toFixed(1) + " ";
    msg += "sender:" + sender;

    if(vel.length() > 400){
        server.disconnect_client(cp.clientnum, 3);
        eventdata.bypass = true;
    }
    //if(vel.length() > 100) server.forcespectator(cp.clientnum);
    //if(vel.length() > 100) server.rename(cp.clientnum, "Gino");
    //if(vel.length() > 100) server.rename2(cp.clientnum, "Gino");
    //if(vel.length() > 100) server.playsound(cp.clientnum, Sound.S_DIE2);

    //server.sendservmsg(msg);
    //server.conout(Conout.CON_WARN, msg);
}

function onTeleport(ci, cp, pcn, teleport, teledest, sender, chan, eventdata){
    var msg = "N_TELEPORT";
    msg += "ci: " + ci.name + " ";
    if(cp) {msg += "cp: " + cp.name + " "};
    msg += "pcn: " + pcn + " ";
    msg += "tport: " + teleport + " ";
    msg += "tdest: " + teledest + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onJumppad(ci, cp, pcn, jumppad, sender, chan, eventdata){
    var msg = "N_JUMPPAD ";
    msg += "ci: " + ci.name + " ";
    if(cn) {msg += "cp: " + cp.name + " "};
    msg += "pcn: " + pcn + " ";
    msg += "jpad: " + jumppad + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onFromai(ci, qcn, sender, chan, eventdata){
    var msg = "N_FROMAI ";
    msg += "ci: " + ci.name + " ";
    msg += "qcn: " + qcn + " ";
    msg += "sndr: " + sender;
    //server.sendservmsg(msg); //this is quite verbose
}

function onMapcrc(ci, crc, sender, chan, eventdata){
    var msg = "N_MAPCRC ";
    msg += "ci: " + ci.name + " ";
    msg += "crc: " + crc + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onCheckmaps(ci, sender, chan, eventdata){
    var msg = "N_CHECKMAPS ";
    msg += "ci: " + ci.name + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onEditmode(ci, val, sender, chan, eventdata){
    var msg = "N_CHECKMAPS ";
    msg += "ci: " + ci.name + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onTryspawn(ci, cq, sender, chan, eventdata){
    var msg = "N_TRYSPAWN ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onGunselect(ci, gunselect, sender, chan, eventdata){
    var msg = "N_GUNSELECT ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "gunslct: " + gunselect + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onSpawn(ci, cq, cm, ls, gunselect, sender, chan, eventdata){
    var msg = "N_SPAWN ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    if(cm) {msg += "cm: " + cq.name + " ";}
    msg += "ls: " + ls + " ";
    msg += "gunslct: " + gunselect + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onSuicide(ci, cq, sender, chan, eventdata){
    var msg = "N_SUICIDE ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}

function onShoot(ci, cq, shot, sender, chan, eventdata){
    var newFrom = new Vec(1.0, 2.0, 3.0);
    shot.from = newFrom.toArray();

    var msg = "N_SHOOT ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "from: " + shot.from;
    msg += "from[0]: " + shot.from[0];
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}


function onText(ci, text){
    server.sendservmsg(text);
}
