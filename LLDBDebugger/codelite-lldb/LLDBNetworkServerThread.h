#ifndef LLDBNETWORKSERVERTHREAD_H
#define LLDBNETWORKSERVERTHREAD_H

#include <wx/thread.h>
#include "LLDBProtocol/cl_socket_base.h"

class CodeLiteLLDBApp;
class LLDBNetworkServerThread : public wxThread
{
    CodeLiteLLDBApp* m_app;
    clSocketBase::Ptr_t m_socket;
public:
    LLDBNetworkServerThread(CodeLiteLLDBApp* app, int fd);
    virtual ~LLDBNetworkServerThread();

    virtual void* Entry();
    
    void Start() {
        Create();
        Run();
    }
};

#endif // LLDBNETWORKSERVERTHREAD_H