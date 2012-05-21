import QtQuick 1.1
import com.nokia.meego 1.0

Page {

    tools: commonTools

    TittleBar{
        id: tittleBar;
        tittle: "mac2wepkey";
        color: "green";
    }

    TabGroup {
        id: tabgroup
        anchors.top: tittleBar.bottom
        anchors.bottom: parent.bottom
        currentTab: writePage;

        WritePage{
            id: writePage;
        }

        NetworkList{
            id: networkListPage;
        }
    }

    ToolBarLayout {
        id: commonTools
        visible: true

        ButtonRow {
            checkedButton: writeBtn;
            style: TabButtonStyle { }

            TabButton {
                id: networkListBtn;
                tab: networkListPage;
                Image{
                    x: parent.width/2-width/2
                    y: parent.height/2 - height/2
                    source: "qrc:/resources/icons/networks.png";
                }

                onClicked: {
                    myMenu.close();
                }
            }

            TabButton {
                id: writeBtn;
                tab: writePage;
                Image{
                    x: parent.width/2-width/2
                    y: parent.height/2 - height/2
                    source: "qrc:/resources/icons/input.png";
                }

                onClicked: {
                    myMenu.close()
                }
            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked:{
                (myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
            }
        }
    }
}
