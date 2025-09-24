let tasks = [
  { id: 1, title: "HTML&CSS", isDone: true },
  { id: 2, title: "JS", isDone: true },
  { id: 3, title: "ReactJS", isDone: false },
  { id: 4, title: "Rest API", isDone: false },
  { id: 5, title: "GraphQL", isDone: false },
];

let addedTask = { id: 77, title: "Java", isDone: false};
let updated = [...tasks, addedTask];

console.log(updated);