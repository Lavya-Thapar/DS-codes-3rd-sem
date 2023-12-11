// function createCircle(rad){
//     return{
//         radius:rad,
//         draw:function(){
//             console.log("draw")
//         }
//     };
// }
// const circle=createCircle(5)
// let rad=circle.radius;
// circle.circumference=20;//you can also add properties externally like this 
// console.log(circle.circumference)
// console.log(rad);
// function car(model)
// {
//     this.model=model;
//     this.price=500000;
//     this.drive=function(){
//         console.log("driving");
//     }
// }
// const car1=new car(55);
// console.log(car1.model)
// for(let keys in circle)
// {
//     console.log(keys,circle[keys]);
// }
// const keys=Object.keys(circle);//Object is a property of objects 
// console.log(keys);//returns array of keys
// //to check existence of properties use "in" operator
// if('radius' in circle)
// {
//     console.log("circle has radius");
// }
// const object1={
    
//     greet()
//     {
//         console.log("hello there");
//     }
// }
// function Object1(city){
//     this.city=city
// }
// Object.assign(Object1.prototype,object1);
// const object3=new Object1("madrid");
// object3.greet();
class teacher{
    #name;
    subject;
    constructor(name,subject)
    {
        this.#name=name;
        this.subject=subject;
    }
    introduce(){
        console.log(`my name is ${this.name } and I teach ${this.subject}`);
    }
    return_name()
    {
        return this.#name;
    }
}
const teacher1=new teacher("Rohan","Maths");
console.log(teacher1.return_name());
