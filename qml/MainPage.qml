import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    width: 480
    tools: commonTools

    TittleBar{
	id: tittleBar;
	tittle: "Kall";
	author: "By Iktwo";
	color: "green";
	logo: "qrc:/logo.png";
	//logo: "qrc:/backspace.png";
	logoLink: "http://store.ovi.mobi/publisher/Iktwo/";
	//tittleLink: "http://store.ovi.mobi/content/213823";
	authorLink: "http://store.ovi.mobi/publisher/Iktwo/";
    }

    Rectangle {
	id: rectangle1
	y: 73
	height: 120
	color: "#211c21"
	anchors.right: parent.right
	anchors.rightMargin: 0
	anchors.left: parent.left
	anchors.leftMargin: 0

	Text {
	    id: number
	    width: 420
	    height: 120
	    color: "#ffffff"
	    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
	    horizontalAlignment: Text.AlignRight
	    verticalAlignment: Text.AlignVCenter
	    anchors.right: btnBack.right
	    anchors.top: parent.top
	    anchors.bottom: parent.bottom
	    font.pointSize: 35
	}

	MouseArea{
	    x: 420
	    y: 0
	    width: 60
	    height: 120
	    onClicked: {
		number.text = number.text.substring(0,number.text.length-1)
	    }
	    onPressed: {
		btnBack.state = "PRESSED"
	    }

	    onReleased: {
		btnBack.state = "NORMAL"
	    }

	    Image {
		id: btnBack
		x: 0
		y: 0
		width: 48
		height: 48
		source: "qrc:/backspace.png"
		anchors.verticalCenter: parent.verticalCenter

		states: [
		    State {
			name: "NORMAL"
			PropertyChanges {
			    target: btnBack;
			    source: "qrc:/backspace.png";
			}
		    },
		    State {
			name: "PRESSED"
			PropertyChanges {
			    target: btnBack;
			    source: "qrc:/backspace-selected.png";
			}
		    }
		]
	    }
	}
    }

    KeypadButton{
	id: button1;
	x: 20
	y: 194
	text: "1";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "1"
	    }
	}
    }

    KeypadButton{
	id: button2;
	x: 190
	y: 194
	text: "2";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "2"
	    }
	}
    }

    KeypadButton{
	id: button3;
	x: 350
	y: 194
	text: "3";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "3"
	    }
	}
    }

    KeypadButton{
	id: button4;
	x: 20
	y: 314
	text: "4";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "4"
	    }
	}
    }
    KeypadButton{
	id: button5;
	x: 190
	y: 314
	text: "5";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "5"
	    }
	}
    }

    KeypadButton{
	id: button6;
	x: 350
	y: 314
	text: "6";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "6"
	    }
	}
    }

    KeypadButton{
	id: button7;
	x: 20
	y: 434
	text: "7";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "7"
	    }
	}
    }

    KeypadButton{
	id: button8;
	x: 190
	y: 434
	text: "8";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "8"
	    }
	}
    }

    KeypadButton{
	id: button9;
	x: 350
	y: 434
	text: "9";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "9"
	    }
	}
    }


    KeypadButton{
	id: buttonStar;
	x: 20
	y: 554
	text: "*";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "*"
	    }
	}
    }

    KeypadButton{
	id: button0;
	x: 190
	y: 554
	text: "0";
	onPressed: {
	    if (number.text.length<30){
		number.text = number.text + "0"
	    }
	}
    }

    Button{
	text: "Kall"
	width: 210;
	height: 62;
	x: 20
	y: 554 + 110
	onClicked: {
	    wMain.kall(number.text);
	}

	platformStyle: ButtonStyle{
	    background: "image://theme/color2-meegotouch-button-accent-background"
	    pressedBackground: "image://theme/color2-meegotouch-button-accent-background-pressed"
	}
    }
}
