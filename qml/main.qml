import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    MainPage {
        id: mainPage
        orientationLock: PageOrientation.LockPortrait
    }

    SettingsPage {
        id: settingsPage
        orientationLock: PageOrientation.LockPortrait
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-settings"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: {
                onClicked: {
                    pageStack.push(settingsPage);
                }
            }
        }
    }

    AboutDialog{
        id: myDialog
    }
}
