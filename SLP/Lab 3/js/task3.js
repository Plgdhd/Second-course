function sortStudentsByGroup(students)
{
    let resultObj = {};

    students.forEach(student => {
        let{name, age, groupId} = student;
        if (age > 17) {
        if (resultObj[groupId]) {
          resultObj[groupId].push(student);
        } else {
          resultObj[groupId] = [student];
        }
      }
    });
    return resultObj;
}

let students = [
    {name: "Oleg", age: 17, groupId: 1},
    {name: "Glebas", age: 17, groupId: 2},
    {name: "Pasha Beloded", age: 29, groupId: 2},
    {name: "Bob", age: 15, groupId: 1},
    {name: "Vadim", age: 18, groupId: 1}
];

let sortedStudents = sortStudentsByGroup(students);
console.log(sortedStudents);