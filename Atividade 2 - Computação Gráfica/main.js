$(document).ready(function(){

    $(window).scroll(function(){
        // sticky navbar on scroll script
        if(this.scrollY > 10){
            $('.navbar').addClass("sticky");
        }else{
            $('.navbar').removeClass("sticky");
        }
        
        // scroll-up button show/hide script
        if(this.scrollY > 500){
            $('.scroll-up-btn').addClass("show");
        }else{
            $('.scroll-up-btn').removeClass("show");
        }
    });

     // typing text animation script
     var typed = new Typed(".typing", {
        strings: ["DDA", "Bresenham", "Círculo Simples", "Ponto Médio"],
        typeSpeed: 100,
        backSpeed: 60,
        loop: true
    });

    var typed = new Typed(".typing-2", {
        strings: ["DDA", "Bresenham", "Círculo Simples", "Ponto Médio"],
        typeSpeed: 100,
        backSpeed: 60,
        loop: true
    });

    
});