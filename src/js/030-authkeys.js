/**

  Authkeys management

  If automatic js loading is not disabled, all keys added to this file will
  be loaded instantly into the server.

  */

server.clearusers();

function Authkey(name, domain, pubkey, privilege) {
    this.name = name;
    this.domain = domain;
    this.pubkey = pubkey;
    this.privilege = privilege; // 'a', 'm', or 'n'
}

var authkeys = [];

//to add keys, just duplicate the following line:
authkeys.push(new Authkey("Gustavo", "gustavo", "-1cc253692d7b69d6c8b5ab737970b4ebdaf19679d7c07c9d", "a"));

for(var a=0; a<authkeys.length; a++){
    server.adduser(
                authkeys[a].name,
                authkeys[a].domain,
                authkeys[a].pubkey,
                authkeys[a].privilege);
}
