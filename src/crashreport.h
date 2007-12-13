#ifndef CRASHREPORT_H_INCLUDED
#define CRASHREPORT_H_INCLUDED

#include <wx/debugrpt.h>

#if wxUSE_DEBUGREPORT

class NetDebugReport : public wxDebugReportUpload /// FIXME (BrainDamage#1#): this doesn't do anything
{
  public:
      NetDebugReport() : wxDebugReportUpload
                       (
                        _T("http://www.zjt3.com"),
                        _T("debugfile"),
                        _T("test.py")
                       )
      {
      }

  protected:
      bool OnServerReply(const wxArrayString& reply);
};

class CrashReport
{
  public:

    CrashReport(){}

    void GenerateReport(wxDebugReport::Context ctx);

};

#else // wxUSE_DEBUGREPORT

class CrashReport
{
  public:

    CrashReport() {}

    void GenerateReport(wxDebugReport::Context ctx);
};

#endif // !wxUSE_DEBUGREPORT

CrashReport& crashreport();

#endif // SPRINGLOBBY_HEADERGUARD_CRASHREPORT_H_INCLUDED
