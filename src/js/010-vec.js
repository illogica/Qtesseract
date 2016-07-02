/**

  A simple math Vector library encapsulating 3 floats.
  Useful to work with Tesseract 'vec' class.
  Note: the 'vec' c++ class is not directly accessible by the js environment. Vecs are passed by
  their internal values (they don't extend QObject, to keep them very light),
  and need to be reassigned before the function returns if you want to modify them, e.g.:

function onShoot(ci, cq, shot, sender, chan, eventdata){
    //shot is a c++ object with two vec: from and to

    var newFrom = new Vec(1.0, 2.0, 3.0); //create a new Vec js object

    [...]

    shot.from = newFrom.toArray(); // save it into the c++ vec struct
}

  */

function Vec(x, y, z) {
    this.x = x || 0;
    this.y = y || 0;
    this.z = z || 0;
}

Vec.prototype.set = function(x, y, z){
    this.x = x;
    this.y = y;
    this.z = z;
    return this;
}

Vec.prototype.setX = function(x){
    this.x = x;
    return this;
}

Vec.prototype.setY = function(y){
    this.y = y
    return this;
}

Vec.prototype.setZ = function(z){
    this.z = z;
    return this;
}

Vec.prototype.add = function(vec){
    this.x += vec.x;
    this.y += vec.y;
    this.z += vec.z;
    return this;
}

Vec.prototype.addScalar = function(scalar){
    this.x += scalar;
    this.y += scalar;
    this.z += scalar;
    return this;
}

Vec.prototype.sub = function(vec){
    this.x -= vec.x;
    this.y -= vec.y;
    this.z -= vec.z;
    return this;
}

Vec.prototype.subScalar = function(scalar){
    this.x -= scalar;
    this.y -= scalar;
    this.z -= scalar;
    return this;
}

Vec.prototype.mul = function(vec){
    this.x *= vec.x;
    this.y *= vec.y;
    this.z *= vec.z;
    return this;
}

Vec.prototype.mulScalar = function(scalar){
    this.x *= scalar;
    this.y *= scalar;
    this.z *= scalar;
    return this;
}

Vec.prototype.div = function(vec){
    if(vec.x !== 0)
        this.x /= vec.x;
    else
        this.x = 0;
    if(vec.y !== 0)
        this.y /= vec.y;
    else
        this.y = 0;
    if(vec.z !== 0)
        this.z /= vec.z;
    else
        this.z = 0;
    return this;
}

Vec.prototype.divScalar = function(scalar){
    if(scalar !== 0){
        this.x /= scalar;
        this.y /= scalar;
        this.z /= scalar;
    } else {
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }
    return this;
}

Vec.prototype.invert = function(){
    this.x *= -1;
    this.y *= -1;
    this.z *= -1;
    return this;
}

Vec.prototype.dot = function(vec){
    return this.x * vec.x + this.y * vec.y + this.z * vec.z;
}

Vec.prototype.cross2 = function(a, b){
    this.x = a.y * b.z - a.z * b.y;
    this.y = a.z * b.x - a.x * b.z;
    this.z = a.x * b.y - a.y * b.x;
    return this;
}

Vec.prototype.cross = function (v) {
    var x = this.x, y = this.y, z = this.z;
    this.x = y * v.z - z * v.y;
    this.y = z * v.x - x * v.z;
    this.z = x * v.y - y * v.x;
    return this;
}

Vec.prototype.magnitude = function(){
    return Math.sqrt((this.x * this.x) + (this.y * this.y) + (this.z*this.z));
}

Vec.prototype.norm = function(){
    this.divScalar(this.length());
}

Vec.prototype.length = Vec.prototype.magnitude

Vec.prototype.clone = function(){
    return new Vec(this.x, this.y, this.z);
}

Vec.prototype.isZero = function(){
    return (this.length() < 0.0001);
}

/*
  Needed for vec assignements:
    var newFrom = new Vec(1.0, 2.0, 3.0);
    shot.from = newFrom.toArray();
*/
Vec.prototype.toArray = function(){
    return [this.x, this.y, this.z]
}
