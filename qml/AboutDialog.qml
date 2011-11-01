import QtQuick 1.0
import com.nokia.meego 1.0

QueryDialog {
    id: aboutDialog

    titleText: "Kall by Iktwo " + "1.0.0"
    icon: "qrc:/kall80.png"
    message: qsTr("Make a Call and automatically terminate (kill) it after some given time. <br><br> &copy; Iktwo 2011<br><br>Bugs/Comments <br> Send me an <a href=\"mailto:elmaildeliktwo@gmail.com\"> email</a>")
}
