const overlay = document.getElementById('overlay');

const closeM = document.getElementById('close');

const openM =document.getElementById('open');

openM.addEventListener('click', function(){
  overlay.classList.add('show');
});

closeM.addEventListener('click', function(){
  overlay.classList.remove('show');
});