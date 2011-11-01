import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    width: 480
    tools: settingsTools

    ToolBarLayout {
	id: settingsTools
	visible: false

	ToolIcon {
	    platformIconId: "toolbar-back"
	    anchors.left: (parent === undefined) ? undefined : parent.left
	    onClicked: {
		pageStack.pop();
		myMenu.close();

		wMain.setKallTime(time.value);

		/*if (switchSeconds.checked){
		    wMain.setKallTime(time.value);
		}else{
		    wMain.setKallTime(time.value*60);
		}*/
	    }
	}

	ToolIcon {
	    platformIconId: "toolbar-view-menu"
	    anchors.right: (parent === undefined) ? undefined : parent.right
	    onClicked: {
		(myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
	    }
	}
    }

    Menu {
	id: myMenu
	visualParent: pageStack
	MenuLayout {
	    MenuItem {
		text: qsTr("About Kall")
		onClicked: myDialog.open();
	    }
	}
    }

    TittleBar{
	tittle: "Kall"
	author: "Settings"
	color: "green"
	logoWidth: 0;
    }

    Text {
	id: displayText
	text: qsTr("Seconds")
	opacity: 0;
    }

    Row{
	id: row1
	spacing: 10;
	y: 73 + 10
	height: 92
	anchors.rightMargin: 15
	anchors.leftMargin: 15
	anchors.left: parent.left
	anchors.right: parent.right

	Text{
	    text: "Auto-Redial"
	    font.pointSize: 22;
	    anchors.top: parent.top
	    anchors.bottom: parent.bottom
	}

	Switch {
	    id: switchAutoRedial;
	    checked: autoRedial;
	    platformStyle: SwitchStyle {
		switchOn: "image://theme/color2-meegotouch-switch-on"
	    }

	    onCheckedChanged: {
		wMain.setAutoRedial(switchAutoRedial.checked);
	    }
	}
    }

    /*Row{
	y: 73+10+10+92
	height: 92
	anchors.rightMargin: 15
	anchors.leftMargin: 15
	anchors.left: parent.left
	anchors.right: parent.right
	spacing: 10;
	Text{
	    text: "Seconds"
	    font.pointSize: 22;
	    anchors.top: parent.top
	    anchors.bottom: parent.bottom
	}

	Switch {
	    id: switchSeconds;
	    checked: seconds;
	    platformStyle: SwitchStyle {
		switchOn: "image://theme/color2-meegotouch-switch-on"
	    }

	    onCheckedChanged: {
		wMain.setSeconds(switchSeconds.checked);
		if (checked){
		    //time.valueIndicatorText= time.value+" seconds";
		    displayText.text = "Seconds";
		    time.minimumValue= 5;
		    time.maximumValue= 300;
		    time.stepSize=5;
		}else{
		    //time.valueIndicatorText= time.value+" minutes";
		    displayText.text = "Minutes";
		    time.minimumValue= 1;
		    time.maximumValue= 60;
		    time.stepSize=5;
		}
	    }
	}
    }*/

    Row{
	//y: 73+10+10+10+92+92
	y: 73+10+10+92
	spacing: 10;
	height: 92
	anchors.leftMargin: 15
	anchors.rightMargin: 15
	anchors.left: parent.left
	anchors.right: parent.right
	Text{
	    text: "Time"
	    font.pointSize: 22;
	    anchors.top: parent.top
	    anchors.bottom: parent.bottom
	}

	Slider{
	    id: time;
	    valueIndicatorText: value+" "+displayText.text;
	    minimumValue: 5;
	    maximumValue: 300;
	    stepSize: 5;
	    value: kallTime;
	    valueIndicatorVisible: true;

	    platformStyle: SliderStyle{
		grooveItemElapsedBackground:"image://theme/color2-meegotouch-slider-elapsed-background-horizontal"
	    }
	}
    }
}
