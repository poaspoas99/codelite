#ifndef CLTREEKEYBOARDINPUT_H
#define CLTREEKEYBOARDINPUT_H

#include "codelite_exports.h"
#include "wx/event.h"
#include <wx/sharedptr.h>
#include <wx/treebase.h>

class wxTextCtrl;
class wxTreeCtrl;
class WXDLLIMPEXP_SDK clTreeKeyboardInput : public wxEvtHandler
{

public:
    typedef wxSharedPtr<clTreeKeyboardInput> Ptr_t;

    enum eSearchFlags {
        kNone = 0,             // 0
        kRecursive = (1 << 0), // 1
    };

protected:
    wxTreeCtrl* m_tree;
    wxTextCtrl* m_text;
    eSearchFlags m_flags;

protected:
    void OnKeyDown(wxKeyEvent& event);
    void OnTextKeyDown(wxKeyEvent& event);
    void OnTextUpdated(wxCommandEvent& event);
    void OnTreeFocus(wxFocusEvent& event);
    
    void SelecteItem(const wxTreeItemId& item);
    bool CheckItemForMatch(const wxTreeItemId& item);
    
public:
    clTreeKeyboardInput(wxTreeCtrl* tree, eSearchFlags flags = kNone);
    virtual ~clTreeKeyboardInput();
};

#endif // CLTREEKEYBOARDINPUT_H