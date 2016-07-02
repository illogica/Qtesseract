/**

  Handler for the #rename command

  #rename <cn> <opt:newname> will rename player cn to 'unnamed' or to 'newname' if provided

  */

commands.add(new Command("rename", commandRename, "#rename <cn> <newname>: Renames user cn with newname"));
function commandRename(ci, args){
    if(ci.privilege < Privilege.PRIV_MASTER)
        server.sendplayermsg(ci.clientnum, "Insufficient privilege.");
    else {
        var tkz = args.split(" ");
        if(tkz.length === 0){
            server.sendplayermsg(ci.clientnum, "Missing parameters to #rename.");
        }

        var n = parseInt(tkz[0]);
        if(isNaN(n) || n===null || n<0 || n>128){
            server.sendplayermsg(ci.clientnum, "Wrong parameter type to <cn>. Should be an int.");
            return;
        }

        if(tkz[1]===null){
            server.rename(n, "unnamed");
        }

        else {
            server.rename(n, tkz[1]);
        }
    }
}
