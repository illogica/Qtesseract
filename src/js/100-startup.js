
function startup() {
    console.log("JS startup" + Events.N_WELCOME + " hey hey hey!");
}

server.registerHook(Events.N_CONNECT, "onConnect", true);
server.registerHook(Events.N_POS, "onPos", false);
server.registerHook(Events.N_TEXT, "onText", false);

function onConnect(ci, password, authdesc, authname, sender, chan){
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
}

function onPos(ci, cp, pcn, posx, posy, posz, velx, vely, velz, sender){
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

    ///if(vel.length() > 100) server.disconnect_client(cp.clientnum, 3);
    if(vel.length() > 100) server.forcespectator(cp.clientnum);

    //server.sendservmsg(msg);
    server.conout(Conout.CON_WARN, msg);
}

function onText(ci, text){
    server.sendservmsg(text);
}
