//---------------------------------------------------------------------------
// See LICENSE
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// textadeptcm.h
//---------------------------------------------------------------------------

// Old GUID
// {120b94b5-2e6a-4f13-94d0-414bcb64fa0f}
//DEFINE_GUID(CLSID_ShellExtension, 0x120b94b5, 0x2e6a, 0x4f13, 0x94, 0xd0, 0x41, 0x4b, 0xcb, 0x64, 0xfa, 0x0f);

// New GUID since version 1.3.1
// Created to avoid conflict with Notpad++ reusing this code with the GUID above
// {C4ACBD3E-6114-4618-904C-B206ABA9DEB0}
//DEFINE_GUID(CLSID_ShellExtension,
//            0xc4acbd3e, 0x6114, 0x4618, 0x90, 0x4c, 0xb2, 0x6, 0xab, 0xa9, 0xde, 0xb0);

// New GUID for textadeptcm
// Created to avoid conflict with wscitecm using this code with the GUID above
// {16E62371-5256-41BF-8152-B2AA84E1D269}
DEFINE_GUID(CLSID_ShellExtension, 
            0x16e62371, 0x5256, 0x41bf, 0x81, 0x52, 0xb2, 0xaa, 0x84, 0xe1, 0xd2, 0x69);

class CShellExtClassFactory : public IClassFactory {
protected:
  ULONG m_cRef;

public:
  CShellExtClassFactory();
  ~CShellExtClassFactory();

  STDMETHODIMP QueryInterface(REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();
  STDMETHODIMP CreateInstance(LPUNKNOWN, REFIID, LPVOID FAR *);
  STDMETHODIMP LockServer(BOOL);
};
typedef CShellExtClassFactory *LPCSHELLEXTCLASSFACTORY;

class CShellExt : public IContextMenu, IShellExtInit {
public:
protected:
  ULONG m_cRef;
  UINT m_cbFiles;
  STGMEDIUM m_stgMedium;
  LPDATAOBJECT m_pDataObj;
  HBITMAP m_hSciteBmp;
  LPMALLOC m_pAlloc;
  TCHAR m_szDllDir [MAX_PATH];

  STDMETHODIMP InvokeTextadept(HWND hParent,
    LPCSTR pszWorkingDir,
    LPCSTR pszCmd,
    LPCSTR pszParam,
    int iShowCmd);

public:
  CShellExt();
  ~CShellExt();

  STDMETHODIMP QueryInterface(REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  STDMETHODIMP QueryContextMenu(HMENU hMenu,
    UINT indexMenu,
    UINT idCmdFirst,
    UINT idCmdLast,
    UINT uFlags);

  STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO lpcmi);

  STDMETHODIMP GetCommandString(UINT_PTR idCmd,
    UINT uFlags,
    UINT FAR *reserved,
    LPSTR pszName,
    UINT cchMax);

  STDMETHODIMP Initialize(LPCITEMIDLIST pIDFolder,
    LPDATAOBJECT pDataObj,
    HKEY hKeyID);
};

typedef CShellExt *LPCSHELLEXT;
