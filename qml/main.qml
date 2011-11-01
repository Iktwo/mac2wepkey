import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    //showStatusBar: false
    //showToolBar: false

    MainPage {
	id: mainPage

	anchors.top: parent.top
	anchors.left: parent.left
	anchors.right: parent.right
	anchors.bottom: commonTools.top
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {

	    MenuItem { text: qsTr("About")
		onClicked: myDialog.open();
	    }

	    MenuItem { text: qsTr("Quit")
		onClicked: wMain.quit();
	    }
        }
    }

    AboutDialog{
	id: myDialog
    }
}
