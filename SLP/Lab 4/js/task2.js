class Student {
  constructor(name, recordBookNumber, group) {
    this.name = fullName;
    this.recordBookNumber = recordBookNumber;
    this.group = group;
  }
}

let set = new Set(
  new Student("Паша Белодед", 42, 9),
  new Student("Костян", 34, 3),
  new Student("я", 7, 9)
);

function addStudent(student) {
  set.add(student);
}

function deleteByNumber(number) {
    set.delete(number);
}

function filterByGroup(group) {
    return Array.from(set).filter(student => student.group === group);
}

function sortById() {
    return Array.from(students).sort((a, b) => a.id - b.id);
}
