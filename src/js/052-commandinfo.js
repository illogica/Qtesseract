/**

  Handler for the #info command

  #help just shows an info string

  */

commands.add(new Command("info", commandInfo, "#info: Shows some brief information on this server"));
function commandInfo(ci, args){
    var str = "Qtesseract mod: A Tesseract mod extended with Qt libraries and javascript. Kindly brought to you by \f0Gustavo\f7La\f3Pasta";
    server.sendplayermsg(ci.clientnum, str);
}
