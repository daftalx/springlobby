#ifndef CUSTOM_MSG_BOX_H_
#define CUSTOM_MSG_BOX_H_

#include <wx/msgdlg.h>
#include <wx/defs.h>
#include <wx/dialog.h>

#define SL_MAIN_ICON 1
#define SS_MAIN_ICON 2

class wxIcon;
class wxWindow;
class wxPoint;
class wxString;
class wxTextCtrl;
class wxCommandEvent;
class wxCloseEvent;
class wxFocusEvent;

#define SL_MAIN_WINDOW_PTR CustomMessageBox::getLobbypointer()
#define SE_FRAME_PTR CustomMessageBox::getSettingspointer()

int customMessageBox(int whichIcon , const wxString& message,
        const wxString& caption = wxMessageBoxCaptionStr,
        long style = wxOK|wxCENTRE,  const int x = -1, const int y = -1 );
void customMessageBoxNoModal(int whichIcon , const wxString& message,
        const wxString& caption = wxMessageBoxCaptionStr,
        long style = wxOK|wxCENTRE,  const int x = -1, const int y = -1 );



class CustomMessageBox : public wxMessageDialog
{
public:
	CustomMessageBox(wxIcon* icon ,wxWindow *parent, const wxString& message,
	        const wxString& caption = wxMessageBoxCaptionStr,
	        long style = wxOK|wxCENTRE, const wxPoint& pos = wxDefaultPosition);
	virtual ~CustomMessageBox();
	static void setLobbypointer(wxWindow*);
	static void setSettingspointer(wxWindow*);
	static wxWindow* getLobbypointer();
	static wxWindow* getSettingspointer();
    bool Show(bool show);
    void OnButton2(wxCommandEvent& event);
    void OnButton3(wxFocusEvent& event);
    void OnCloseWindow(wxCloseEvent& event);

protected:
	static wxWindow* m_settingsWindow;
	static wxWindow* m_lobbyWindow;


};

class CreditsDialog: public wxDialog
{
public:
	CreditsDialog(wxWindow* parent,wxString title, int whichIcon);
	virtual ~CreditsDialog();
	void AddCredit(wxString,wxString);

private:
	wxTextCtrl* text_ctrl;
};

#endif /*CUSTOM_MSG_DLG_H_*/
