// var countel=document.getElementById("count-el");
// let count=0
// function increment()
// {
//     count=count+1
//     countel.innerText=count;
// }
function callback()
{
    setTimeout(()=>{
        const data={user:"Lavya"}
        setTimeout(()=>{
            console.log("data has been modified")
        },0)
    },0)
}
callback();
const promise =new Promise((resolve,reject)=>{
    setTimeout(()=>{
        let roll_no=[1,2,3,4,5];
        resolve(roll_no)//if roll number fetched then this function will be called
        reject("no data recieved")//if not fetched ..error is passed

    },2000)
})
const biodata=(roll_number)=>{
    return new Promise((resolve,reject)=>{
        setTimeout((roll_number)=>{
            resolve(`my roll number is ${roll_number}`)
            reject("roll number nhi mila");
        },2000,roll_number)
    })
}
// promise
// .then((data)=>{
//     console.log(data)
//     return biodata(data[2])
// }).then((andar_ka_data)=>{
//     console.log(andar_ka_data)
// }).catch((error)=>{
//     console.log(error)
// })
// .catch((error)=>{
//     console.log(error)
// })
async function return_promise()
{
    try{
        const my_promise=await promise;
        console.log(my_promise);
        
    }
    catch(error)
    {
        console.log(error);
    }
}
return_promise();