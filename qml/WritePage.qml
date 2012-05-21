import QtQuick 1.0
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {

    function insertChar(character){
        var mac = txtMac.text;

        if (mac.length<17){
            if (mac.length>10){
                txtMac.text=mac+character;
                if (mac.length==13){
                    txtMac.text=txtMac.text+":";
                }
            }else if(mac.length>7){
                txtMac.text=mac+character;
                if (mac.length==10){
                    txtMac.text=txtMac.text+":";
                }
            }else if(mac.length>5){
                txtMac.text=mac+character;
                if (mac.length==7){
                    txtMac.text=txtMac.text+":";
                }
            }else if (mac.length>2){
                txtMac.text=mac+character;
                if (txtMac.text.length==5){
                    txtMac.text=txtMac.text+":";
                }
            }else{
                txtMac.text=mac+character;
                if (txtMac.text.length==2){
                    txtMac.text=txtMac.text+":";
                }
            }
        }
    }

    function deleteLast(){
        if (txtMac.text.length>0){
            if (txtMac.text.charAt(txtMac.text.length-1)==':'){
                txtMac.text=txtMac.text.substring(0,txtMac.text.length-2);
            }else{
                txtMac.text=txtMac.text.substring(0,txtMac.text.length-1);
            }
        }
    }

    InfoBanner{
        id: infoBanner;
        timerEnabled: true
        timerShowTime: 2500
        z: 1
    }

    Label {
        id: lblMAC

        anchors.verticalCenter: txtMac.verticalCenter
        anchors.left: parent.left

        text: qsTr("MAC")
    }

    TextArea{
        id: txtMac

        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: lblMAC.right
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        enableSoftwareInputPanel : false
        placeholderText: "__:__:__:__:__:__"
    }

    Label {
        id: lblKey
        text: qsTr("Key")
        width: 92*0.5;
        anchors.verticalCenter: txtKey.verticalCenter
        //anchors.verticalCenterOffset: 30;
    }

    TextArea{
        id: txtKey

        anchors.top: txtMac.bottom
        anchors.topMargin: 10
        anchors.left: lblKey.right
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        enableSoftwareInputPanel : false
    }


    Flow {
        id: flow

        anchors.top: txtKey.bottom
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 2
        anchors.right: parent.right
        anchors.rightMargin: 2

        spacing: 2

        ButtonStyle {
            id: btnStyle
            pressedBackground: "image://theme/color2-meegotouch-button-accent-background"
        }

        Button {
            id: btn0;

            text: "0";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn1;

            text: "1";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn2;

            text: "2";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn3;

            text: "3";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn4;

            text: "4";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn5;

            text: "5";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn6;

            text: "6";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn7;

            text: "7";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn8;

            text: "8";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btn9;

            text: "9";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnA;

            text: "A";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnB;

            text: "B";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnC;

            text: "C";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnD;

            text: "D";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnE;

            text: "E";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }
        Button {
            id: btnF;

            text: "F";
            width: 92;
            height: 92;

            onClicked:{
                insertChar(text);
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnBack;
            width: 92;
            height: 92;
            onClicked: {
                deleteLast();
            }

            Image {
                source: "qrc:/resources/icons/left.png"
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            platformStyle: btnStyle
        }

        Button {
            id: btnClear;
            text: "Clear";
            width: 92;
            height: 92;
            onClicked: {
                txtMac.text="";
                txtKey.text="";
            }

            platformStyle: btnStyle
        }

        Button {
            id: btGetKey;
            text: "Get Key";
            width: 92*2;
            height: 92;
            onClicked: {
                txtKey.text="";
                if (txtMac.text.length>7){
                    txtKey.text=wMain.getTelseyKey(txtMac.text);
                }else{
                    infoBanner.text="Please fill the OUI first";
                    infoBanner.show();
                }
            }
        }
    }
}
