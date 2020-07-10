var animals = {
  text: "Животные",
  childs: [
    {
      text: "Млекопитающие",
      childs: [
        { text: "Коровы" },
        { text: "Ослы" },
        { text: "Собаки" },
        { text: "Тигры" },
      ],
    },
    {
      text: "Другие",
      childs: [{ text: "Змеи" }, { text: "Птицы" }, { text: "Ящерицы" }],
    },
  ],
};
var fish = {
  text: "Рыбы",
  childs: [
    { text: "Аквариумные", childs: [{ text: "Гуппи" }, { text: "Скалярии" }] },

    { text: "Морские", childs: [{ text: "Морская форель" }] },
  ],
};

window.onload = function () {
  var creat = document.createElement("ul");
  format(creat, animals);
  format(creat, fish);

  var body = document.getElementsByTagName("body");
  body[0].appendChild(creat);
};

function format(parnt, who) {
  var cur = document.createElement("li");
  cur.innerHTML = who.text;

  if (who.hasOwnProperty("childs")) {
    var child = document.createElement("ul");

    for (let i of who.childs) {
      format(child, i);
    }

    cur.appendChild(child);
  }
  parnt.appendChild(cur);
}

function smth(parent_node) {
  console.log(parent_node);
  let s = parent_node.children;

  if (s.length > 0) {
    for (let i = 0; i < s.length; i++) smth(s[i]);
  }
}
smth(document.getElementById("html"));
