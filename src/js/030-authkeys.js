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
//thkeys.push(new Authkey("Gustavo", "gustavo", "-1cc253692d7b69d6c8b5ab737970b4ebdaf19679d7c07c9d", "a"));
authkeys.push(new Authkey("GustavoLapasta", "gustavo", "+0f4edc6a81315c60974f532ddda9bbcf410a47559ffdd233", "a"));
authkeys.push(new Authkey("Shag", "gustavo", "-4751bf9630525b622053c10d69690860544dc877265250bc", "m"));
authkeys.push(new Authkey("Star", "gustavo", "+de96f3e0ba5bcb692c86cbb06a695fc3db60debc59ec8355", "m"));
authkeys.push(new Authkey("Fear", "gustavo", "+bf1fa38e7439791d9ff52635575e6a002fdfd532d07d5565", "m"));
authkeys.push(new Authkey("a-monster", "gustavo", "-a5a2ba763973d5af0cd90bb46a663712376e855681672864", "m"));
authkeys.push(new Authkey("Narwhaal", "gustavo", "-f14e1ba9db58e791f5a65ed8443cc28e507572903f0ef5d1", "m"));
authkeys.push(new Authkey("Cs4", "gustavo", "+b7fbb3b4227c69eeda4c6aa328fffd75a0717316a4dedb7f", "m"));
authkeys.push(new Authkey("Benz", "gustavo", "+39d60464f037ec70f11163b3e9e2d5f8b03f8bb1c2423b8c", "m"));
authkeys.push(new Authkey("pisto", "gustavo", "-f16c266e93ef6e4882dd865e56cc3f7d3d84d9b4887e01b7", "m"));
authkeys.push(new Authkey("Swatllama", "gustavo", "-b7a19f6996775d3524d6e4c17f85274c925dd0f8cbe9baae", "m"));
authkeys.push(new Authkey("Bourbon", "gustavo", "-ceb7be8552da06683cb117c585e4bc255b4ca05385646321", "m"));
authkeys.push(new Authkey("Zver", "gustavo", "-b89f2161ffe5d9787e465db4cf21801c192334400dd93292", "m"));
authkeys.push(new Authkey("Duke", "gustavo", "+694670498667548b315c450aaa0fb7a24c1306c5f16bd010", "m"));
authkeys.push(new Authkey("Tuta", "gustavo", "-43599891e272d0886d0ca4a7a7414044f3809d817b9c4771", "m"));
authkeys.push(new Authkey("Renard", "gustavo", "+7af8f62f9f609e8716b97e74b51ff03a067569aaefa608c9", "m"));
authkeys.push(new Authkey("NoobInRage", "gustavo", "-50064a2629d1066ff8edb91c123fe0dbe5dfacd307cf98de", "m"));
authkeys.push(new Authkey("Hamon", "gustavo", "+b2f1ccd8d948924d8347943e806a180511ca9c046cc106c4", "m"));
authkeys.push(new Authkey("Tamin0", "gustavo", "-e90fabcea01534491b27d03f06e96577b3ac2e4ca477a33a", "m"));
authkeys.push(new Authkey("Nix", "gustavo", "+44891d2d609a3a0886e3caf1d419304eb25f34db066cea12", "m"));
authkeys.push(new Authkey("Cubelibre", "gustavo", "+638e4431e153edd6f6687e9d245217b46ce394672240b1f8", "m"));
authkeys.push(new Authkey("C_Classic", "gustavo", "-a449d540cf1c6240700877e7f80bd9b9af9d096d0f82a66f", "m"));
authkeys.push(new Authkey("Didisan", "gustavo", "+e43caf939e1df66a1bc0c3b1a77bc6e65e6d3447f5d8f9bf", "m"));
authkeys.push(new Authkey("Shield", "gustavo", "-414c70eea8667a2500c016b5a81704de115f406e3abb56e8", "m"));
authkeys.push(new Authkey("Brucelee", "gustavo", "+6d3aee57d89250c253e2f46a61b1097bce576ac021d80171", "m"));
authkeys.push(new Authkey("Perussola", "gustavo", "+5aff3a6e8e1f2519d25d01f325876752c2ac905dc8c59f2c", "m"));
authkeys.push(new Authkey("Terence", "gustavo", "-b63902492599912ba797c2c0e54d027661e7e573134235cd", "m"));
authkeys.push(new Authkey("Don", "gustavo", "+6468cdbaddf7ab434a6ce87a5dee0a2fbf9ba13aa0baa105", "m"));
authkeys.push(new Authkey("Sahadar", "gustavo", "+61a89fa5120ec0104da4cb51c1afe618b12c5cd1afda9a8e", "m"));
authkeys.push(new Authkey("Shikjio", "gustavo", "+c3fd8098642b21aeb335967ccaafc1c05e580e0ce253cf80", "m"));
authkeys.push(new Authkey("Buck", "gustavo", "+2cff16be3b865023cd7ba6a33dc62a4a03b4e0b07d4ed718", "m"));
authkeys.push(new Authkey("Epimeteo", "gustavo", "+4a6279ecbf9fccb967c940d9d5cc73a62f0cd86e610391d5", "m"));
authkeys.push(new Authkey("Paklet", "gustavo", "+1bdb6d56d6727a91d65d4609974af70bbab6b07e1bec6f92", "m"));
authkeys.push(new Authkey("ZahariaHome", "gustavo", "-1e30dda790fbc42689ea1125a489f8835a1711dfe702abbb", "m"));
authkeys.push(new Authkey("Muz", "gustavo", "+111c55f69013410e3649d8ee1e54ed5fc4e90c54bd4a6d32", "m"));
authkeys.push(new Authkey("4tune", "gustavo", "+ed20acfcfdedb0c070cc4f9d2092a4ddd8d8da60b0418963", "m"));
authkeys.push(new Authkey("altcineva", "gustavo", "+fe52d18447af421b34f42ca585858306285ae3f4306cf46b", "m"));


for(var a=0; a<authkeys.length; a++){
    server.adduser(
                authkeys[a].name,
                authkeys[a].domain,
                authkeys[a].pubkey,
                authkeys[a].privilege);
}
