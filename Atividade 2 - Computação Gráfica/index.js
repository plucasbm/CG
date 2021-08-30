function DDA() {
    var X1 = parseInt(document.getElementById("x0").value) // x inicial
    var Y1 = parseInt(document.getElementById("y0").value) // y inicial
    var X2 = parseInt(document.getElementById("x1").value) // x final
    var Y2 = parseInt(document.getElementById("y1").value) // y final

    var step;
    var X, Y, Xinc, Yinc;
    step = Math.abs(X2 - X1);
    if (Math.abs(Y2 - Y1) > step)

        step = Math.abs(Y2 - Y1);
    Xinc = (X2 - X1) / step;
    Yinc = (Y2 - Y1) / step;
    X = X1;
    Y = Y1;

    while (X < X2) {
        putpixel1(Math.round(X), Math.round(Y));

        X = X + Xinc;
        Y = Y + Yinc;
    }
}

function bresenham() {

    var x1 = parseInt(document.getElementById("x00").value)
    var y1 = parseInt(document.getElementById("y00").value)
    var x2 = parseInt(document.getElementById("x11").value)
    var y2 = parseInt(document.getElementById("y11").value)

    var dx, dy, p, p2, xy2, x, y, xf;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;
    p2 = 2 * dy;
    xy2 = 2 * (dy - dx);
    if (x1 > x2) {
        x = x2;
        y = y2;
        xf = x1;
    } else {
        x = x1;
        y = y1;
        xf = x2;
    }
    putpixel2(x, y);
    while (x < xf) {
        x++;
        if (p < 0)
            p += p2;
        else {
            y++;
            p += xy2;
        }
        putpixel2(x, y);
    }
}


function midPointCircleDraw() {
    var x_centre = parseInt(document.getElementById("xcentre").value)
    var y_centre = parseInt(document.getElementById("ycentre").value)
    var r = parseInt(document.getElementById("r1").value)
    console.log('r')
    console.log(r)
    console.log('y_centre')
    console.log(y_centre)
    console.log('x_centre')
    console.log(x_centre)
    var x = r, y = 0;
    var a, b, c, d, e, f, g, h;

    a = x + x_centre;
    console.log(a)
    b = y + y_centre;
    console.log(b)
    CirclePoints4(a, b);
    
    if (r > 0) {
        a = x + x_centre;
        console.log(a)
        b = -y + y_centre;
        console.log(b)
        CirclePoints4(a, b);
        c = y + x_centre;
        console.log(c)
        d = x + y_centre;
        console.log(d)
        CirclePoints4(c, d);
        e = -y + x_centre;
        console.log(e)
        f = x + y_centre;
        console.log(f)
        CirclePoints4(e, f);
    }
    var P = 1 - r;
    while (x > y) {
        y++;

        if (P <= 0)
            P = P + 2 * y + 1;

        else {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;

        a = x + x_centre;
        b = y + y_centre;
        CirclePoints4(a, b);
        c = -x + x_centre;
        d = y + y_centre;
        CirclePoints4(c, d);
        e = x + x_centre;
        f = -y + y_centre;
        CirclePoints4(e, f);
        g = -x + x_centre;
        h = -y + y_centre;
        CirclePoints4(g, h);

        if (x != y) {
            a = y + x_centre;
            b = x + y_centre;
            CirclePoints4(a, b);
            c = -y + x_centre;
            d = x + y_centre;
            CirclePoints4(c, d);
            e = y + x_centre;
            f = -x + y_centre;
            CirclePoints4(e, f);
            g = -y + x_centre;
            h = -x + y_centre;
            CirclePoints4(g, h);
        }
    }
}

function clearquadro1() {
    var element = document.getElementById('quadro');
    element.innerHTML = ""

}
function clearquadro2() {
    var element = document.getElementById('quadro2');
    element.innerHTML = ""

}function clearquadro3() {
    var element = document.getElementById('quadro3');
    element.innerHTML = ""

}function clearquadro4() {
    var element = document.getElementById('quadro4');
    element.innerHTML = ""

}


function circle() {
    var radius = parseInt(document.getElementById("r").value)
    var xmiddle = parseInt(document.getElementById("x").value)
    var ymiddle = parseInt(document.getElementById("y").value)
    for (var i = 0; i <= 360; i++) {
        x = parseInt(xmiddle + (radius * Math.sin(i * 2 * (Math.PI / 360))) + 0.5)
        y = parseInt(ymiddle + (radius * Math.cos(i * 2 * (Math.PI / 360))) + 0.5)
        CirclePoints3(x, y)
    }
}

function putpixel1(x, y) {
    var element = document.getElementById('quadro');
    element.innerHTML += "<rect x=" + x + " y=" + y + " width=" + "3" + " height=" + "3" + " style='stroke:black' " + "/>"
}


function CirclePoints3(x, y) {
    var element = document.getElementById('quadro3');
    element.innerHTML += "<rect x=" + x + " y=" + y + " width=" + "3" + " height=" + "3" + " style='stroke:black' " + "/>"
}

function putpixel2(x, y) {
    var element = document.getElementById('quadro2');
    element.innerHTML += "<rect x=" + x + " y=" + y + " width=" + "3" + " height=" + "3" + " style='stroke:black' " + "/>"
}


function CirclePoints4(x, y) {
    var element = document.getElementById('quadro4');
    element.innerHTML += "<rect x=" + x + " y=" + y + " width=" + "3" + " height=" + "3" + " style='stroke:black' " + "/>"
}