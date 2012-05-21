import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    MainPage {
        id: mainPage
        orientationLock: PageOrientation.LockPortrait
        Component.onCompleted: {
            theme.inverted=true;
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {

            MenuItem { text: qsTr("About")
                onClicked: {
                    pageStack.push(aboutDialog);
                }
            }
        }
    }

    AboutDialog{
        id: aboutDialog
    }
}
