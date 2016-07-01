commands.add(new Command("js", commandJs, "#js: evaluates a javascript expression"));
function commandJs(ci, args){
    var result = eval(args);
    server.sendplayermsg(ci.clientnum, result);
}
