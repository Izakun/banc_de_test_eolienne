#include <QString>
#include <QtTest>
#include "../../app/TP_dictionnaire_app/dictionnaire.h"

/*----------------------------------------------------------------------------*/
class TP_dictionnaire_testTest : public QObject
{
        Q_OBJECT

    public:
        TP_dictionnaire_testTest();

    private Q_SLOTS:
        void testCase1();

    private:
        dictionnaire m_dico;
};

/*----------------------------------------------------------------------------*/
TP_dictionnaire_testTest::TP_dictionnaire_testTest()
{
}

/*----------------------------------------------------------------------------*/
void TP_dictionnaire_testTest::testCase1()
{
    QVERIFY2( m_dico.mot_existe("a") == true, "Erreur pour le mot a");
    QVERIFY2( m_dico.mot_existe("bonjour") == true, "Erreur pour le mot bonjour");
    QVERIFY2( m_dico.mot_existe("anticonstitutionnellement") == true, "Erreur pour le mot anticonstitutionnellement");
    QVERIFY2( m_dico.mot_existe("zythums") == true, "Erreur pour le mot zythum");
    QVERIFY2( m_dico.mot_existe("fonjour") == false, "Erreur pour le mot fonjour");
    QVERIFY2( m_dico.mot_existe("trascot") == false, "Erreur pour le mot trascot");
}

QTEST_APPLESS_MAIN(TP_dictionnaire_testTest)

#include "tst_tp_dictionnaire_testtest.moc"
