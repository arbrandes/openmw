#ifndef CSM_DOC_OPERATION_H
#define CSM_DOC_OPERATION_H

#include <vector>

#include <QThread>

namespace CSMDoc
{
    class Stage;

    class Operation : public QThread
    {
            Q_OBJECT

            int mType;
            std::vector<std::pair<Stage *, int> > mStages; // stage, number of steps
            std::vector<std::pair<Stage *, int> >::iterator mCurrentStage;
            int mCurrentStep;
            int mCurrentStepTotal;
            int mTotalSteps;
            int mOrdered;

            void prepareStages();

        public:

            Operation (int type, bool ordered);
            ///< \param parallel Stages must be executed in the given order.

            virtual ~Operation();

            virtual void run();

            void appendStage (Stage *stage);
            ///< The ownership of \a stage is transferred to *this.
            ///
            /// \attention Do no call this function while this Operation is running.

        signals:

            void progress (int current, int max, int type);

            void reportMessage (const QString& message, int type);

        public slots:

            void abort();

        private slots:

            void verify();
    };
}

#endif