
// MiniDrawDoc.h: интерфейс класса CMiniDrawDoc 
//

#include "Afxtempl.h" // шаблоны библиотеки MFC (например, для использования шаблона класса CTypedPtrArray)

#pragma once

class CLine : public CObject
{
protected:
	int m_X1, m_Y1, m_X2, m_Y2;
public:
	CLine(int X1, int Y1, int X2, int Y2) 
	{
		m_X1 = X1; 
		m_Y1 = Y1;
		m_X2 = X2;
		m_Y2 = Y2;
	}
	void Draw(CDC* PDC);
};

class CMiniDrawDoc : public CDocument
{
protected: // создать только из сериализации
	CTypedPtrArray<CObArray, CLine*> m_LineArray;

	CMiniDrawDoc() noexcept;
	DECLARE_DYNCREATE(CMiniDrawDoc)

// Атрибуты
public:
	
// Операции
public:
	void AddLine(int X1, int Y1, int X2, int Y2);
	CLine* GetLine(int Index);
	int GetNumLines();
	// остальные определения класса CMiniDrawDoc.h
	
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMiniDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
