
server.registerHook(FunctionEvent.F_RUGBY, "onRugby");
function onRugby(target, actor) {
    server.sendservmsg("\f2" + actor.name + "\f7 passed to \f2" + target.name + "\f7!");
}
