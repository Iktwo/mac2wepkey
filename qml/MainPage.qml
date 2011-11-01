import QtQuick 1.1
import com.nokia.meego 1.0

Page {

    tools: commonTools

    TittleBar{
        id: tittleBar;
        tittle: "mac2wepkey";
        author: "By Iktwo";
        color: "green";
        logo: "qrc:/icons/logo.png";
        logoLink: "http://store.ovi.mobi/publisher/Iktwo/";
        //tittleLink: "http://store.ovi.mobi/content/213823";
        authorLink: "http://store.ovi.mobi/publisher/Iktwo/";
    }


    Flow {
        id: flow
        x: 0
        y: 0+mainPageColumn.height
        width: 360
        height: parent.height-mainPageColumn.height
        spacing: 2
        anchors.topMargin: 73
        anchors.fill: parent

        Label {
            id: lblOUI
            text: qsTr("MAC")
            width: 92*0.5;

            //anchors.verticalCenter: txtOui.verticalCenter
        }

        TextArea{
            id: txtOui
            width: 92*1.5;
            //text: currentOUI
            enableSoftwareInputPanel : false
            placeholderText: "_:_:_"
            onTextChanged: {
                wMain.updateOUI(txtOui.text);
            }
        }

        Button {
            id: btnSeparator;
            width: 92*3;
            height: txtOui.height;
            opacity: 0.001;
        }

        Label {
            id: lblOrg
            text: qsTr("Key")
            width: 92*0.5;
            anchors.verticalCenter: txtOrg.verticalCenter
            //anchors.verticalCenterOffset: 30;
        }

        TextArea{
            id: txtOrg
            width: 92*4.5;
            text:txtORG;
            enableSoftwareInputPanel : false
        }

        Button {
            id: btn0;
            text: "0";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_0_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }

            /*platformStyle: ButtonStyle{
        //pressedTextColor: "lightgreen"
        pressedBackground: "image://theme/4-meegotouch-button" + __invertedString + "-background-pressed" + (position ? "-" + position : "")
        }*/
        }

        Button {
            id: btn1;
            text: "1";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_1_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn2;
            text: "2";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_2_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn3;
            text: "3";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_3_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn4;
            text: "4";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_4_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn5;
            text: "5";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_5_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn6;
            text: "6";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_6_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn7;
            text: "7";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_7_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn8;
            text: "8";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_8_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btn9;
            text: "9";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_9_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnA;
            text: "A";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_A_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnB;
            text: "B";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_B_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnC;
            text: "C";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_C_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnD;
            text: "D";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_D_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnE;
            text: "E";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_E_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }
        Button {
            id: btnF;
            text: "F";
            width: 92;
            height: 92;
            onClicked:{
                wMain.on_btn_F_pressed(txtOui.text);
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnBack;
            text: "<-";
            width: 92;
            height: 92;
            onClicked: {
                wMain.on_btnBack_pressed();
                txtOui.text=currentOUI;
            }
        }

        Button {
            id: btnClear;
            text: "Clear";
            width: 92;
            height: 92;
            onClicked: {
                wMain.clear();
                txtOui.text="";
                //txtOui.text=currentOUI;
            }
        }

        Button {
            id: btGetOrg;
            text: "Get Org";
            width: 92*2;
            height: 92;
            onClicked: {
                wMain.getOrg();
                txtORG.text=txtORG;
                //txtOui.text=currentOUI;
            }
        }
    }


    state: screen.currentOrientation == Screen.Portrait ? "portrait" : "landscape"

    states: [
        State {
            name: "landscape"
            PropertyChanges { target: btnSeparator; visible: false }
            AnchorChanges  { target: txtOrg; anchors.verticalCenter: btn0.verticalCenter }
            AnchorChanges  { target: txtOui; anchors.verticalCenter: btn0.verticalCenter }

        },
        State {
            name: "portrait"
            PropertyChanges { target: btnSeparator; visible: true }
            AnchorChanges  { target: txtOrg; anchors.verticalCenter: undefined}
            AnchorChanges  { target: txtOui; anchors.verticalCenter: undefined}
        }
    ]

    transitions: Transition {
        PropertyAnimation { properties: "x,y"; duration: 500 }
    }
}
