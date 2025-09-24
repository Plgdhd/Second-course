let store = {
  state: {
    profilePage: {
      posts: [
        { id: 1, message: 'Hi', likesCount: 12 },
        { id: 2, message: 'By', likesCount: 1 },
      ],
      newPostText: 'About me',
    },
    dialogsPage: {
      dialogs: [
        { id: 1, name: 'Valera' },
        { id: 2, name: 'Andrey' },
        { id: 3, name: 'Sasha' },
        { id: 4, name: 'Viktor' },
      ],
      messages: [
        { id: 1, message: 'hi' },
        { id: 2, message: 'hi hi' },
        { id: 3, message: 'hi hi hi' },
      ],
    },
    sidebar: [],
  },
};

let {
  state: {
    profilePage: { posts, newPostText },
    dialogsPage: { dialogs, messages },
    sidebar,
  },
} = store;

let likes = posts.map(p => p.likesCount);
console.log("likesCount:", likes);

let filterDialogs = dialogs.filter(d => d.id % 2 === 0);
console.log("Четные id:", filterDialogs);

let newMessages = messages.map(m => ({ ...m, message: "Hello user" }));
console.log("Messages:", newMessages);
