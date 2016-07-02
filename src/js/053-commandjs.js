/**

  Handler for the #js command

  #js <expression> will evaluate a js expression

  eg:

  #js 1+1                       //will print 2
  #js server.maxclients(32)     //will change maxclients to 32

  */

commands.add(new Command("js", commandJs, "#js <js expression>: evaluates a javascript expression"));
function commandJs(ci, args){
    //if(ci.privilege < Privilege.PRIV_ADMIN)
    //    server.sendplayermsg(ci.clientnum, "Insufficient privilege.");
    //else{
        var result = eval(args);
        server.sendplayermsg(ci.clientnum, result);
    //}
}
