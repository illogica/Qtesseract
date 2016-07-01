commands.add(new Command("js", commandJs, "#js <js expression>: evaluates a javascript expression"));
function commandJs(ci, args){
    //if(ci.privilege < Privilege.PRIV_ADMIN)
    //    server.sendplayermsg(ci.clientnum, "Insufficient privilege.");
    //else{
        var result = eval(args);
        server.sendplayermsg(ci.clientnum, result);
    //}
}
