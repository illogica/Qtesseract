/**

  MAIN SERVER CONFIGURATION

  */

server.maxclients(16);

var motd = "Welcome to Pastaland! Type \f4#help\f7 for more cool stuff, come visit \f2Pastaland.ovh\f7 for more info";
var motd2 = "rCTF and pCTF have \f2rugby mode\f7: when you have the flag, shoot your teammate to pass it!";

server.registerHook(FunctionEvent.F_CONNECTEDPOST, "onPostConnected");
function onPostConnected(ci, eventdata){
    server.sendplayermsg(ci.clientnum, motd);
    server.sendplayermsg(ci.clientnum, motd2);
}



// Handle the server connection on the JS side
server.registerHook(Events.N_CONNECT, "onConnect");
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

    eventdata.bypass = true; //or the server will segfault
}


/**

  Some event hoolk examples follow

  */


//server.registerHook(Events.N_TEXT, "onText");

/*
server.registerHook(Events.N_POS, "onPos");
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
*/

/*
server.registerHook(Events.N_TELEPORT, "onTeleport");
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
*/

/*
server.registerHook(Events.N_JUMPPAD, "onJumppad");
function onJumppad(ci, cp, pcn, jumppad, sender, chan, eventdata){
    var msg = "N_JUMPPAD ";
    msg += "ci: " + ci.name + " ";
    if(cn) {msg += "cp: " + cp.name + " "};
    msg += "pcn: " + pcn + " ";
    msg += "jpad: " + jumppad + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_FROMAI, "onFromai");
function onFromai(ci, qcn, sender, chan, eventdata){
    var msg = "N_FROMAI ";
    msg += "ci: " + ci.name + " ";
    msg += "qcn: " + qcn + " ";
    msg += "sndr: " + sender;
    //server.sendservmsg(msg); //this is quite verbose
}
*/

/*
server.registerHook(Events.N_MAPCRC, "onMapcrc");
function onMapcrc(ci, crc, sender, chan, eventdata){
    var msg = "N_MAPCRC ";
    msg += "ci: " + ci.name + " ";
    msg += "crc: " + crc + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_CHECKMAPS, "onCheckmaps");
function onCheckmaps(ci, sender, chan, eventdata){
    var msg = "N_CHECKMAPS ";
    msg += "ci: " + ci.name + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_EDITMODE, "onEditmode");
function onEditmode(ci, val, sender, chan, eventdata){
    var msg = "N_CHECKMAPS ";
    msg += "ci: " + ci.name + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_TRYSPAWN, "onTryspawn");
function onTryspawn(ci, cq, sender, chan, eventdata){
    var msg = "N_TRYSPAWN ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_GUNSELECT, "onGunselect");
function onGunselect(ci, gunselect, sender, chan, eventdata){
    var msg = "N_GUNSELECT ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "gunslct: " + gunselect + " ";
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_SPAWN, "onSpawn");
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
*/

/*
server.registerHook(Events.N_SUICIDE, "onSuicide");
function onSuicide(ci, cq, sender, chan, eventdata){
    var msg = "N_SUICIDE ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_SHOOT, "onShoot");
function onShoot(ci, cq, shot, sender, chan, eventdata){
    //var newFrom = new Vec(1.0, 2.0, 3.0);
    //shot.from = newFrom.toArray();

    var msg = "N_SHOOT ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "from: " + shot.from;
    msg += "from[0]: " + shot.from[0];
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_EXPLODE, "onExplode");
function onExplode(ci, cq, exp, sender, chan, eventdata){
    var msg = "N_EXPLODE ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "exp.id: " + exp.id;
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/

/*
server.registerHook(Events.N_ITEMPICKUP, "onItempickup");
function onItempickup(ci, cq, pickup, sender, chan, eventdata){
    var msg = "N_ITEMPICKUP ";
    if(ci) {msg += "ci: " + ci.name + " ";}
    if(cq) {msg += "cq: " + cq.name + " ";}
    msg += "pickup.ent: " + pickup.ent;
    msg += "sndr: " + sender;
    server.sendservmsg(msg);
}
*/
