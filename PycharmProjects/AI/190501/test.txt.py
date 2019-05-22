import numpy as np
import matplotlib.pyplot as plt

data = np.array([[0.1875, 0.75, 0.625, 0.0625, 0.9375, 0.4375, 0.75, 0.625, 1, 0, 0.25, 0.75, 0.875, 0.375, 0.625, 0.6875, 0.375, 0.9375, 0.75, 0.0625],
                 [0.5, 1, 1, 0.4375, 0, 0.5, 0.5625, 0, 0, 0.5, 0.5, 0, 0.25, 1, 0.5, 0, 0, 0.375, 0.4375, 0],
                 [0.3125, 0.5, 0.5, 0.5, 0.1875, 0.9375, 0.9375, 0.4375, 0.1875, 0.125, 0.8125, 0.4375, 0.8125, 0.6875, 0.75, 0.5, 0.0625, 0.5625, 0.75, 0.125],
                 [0.4375, 0.75, 0.75, 0.4375, 0.0625, 0.5, 0.625, 0.75, 0.0625, 0.6875, 0.875, 0.5625, 0.3125, 0.3125, 0.6875, 0.4375, 0.375, 0.75, 0.6875, 0.0625],
                 [0.0625, 0.4375, 0.5, 0.1875, 0.6875, 0.75, 0.625, 0.75, 0.75, 0.375, 0.375, 0.6875, 0.1875, 0.875, 0.9375, 0.375, 0, 0.1875, 0.75, 0.125],
                 [0, 0.75, 0.25, 0, 0, 0.625, 0.4375, 0, 0, 0.5, 0.5, 0, 0, 0.5, 0.5625, 0, 0, 0.1875, 0.625, 0],
                 [0.1875, 1, 1, 0.875, 0.0625, 0.8125, 0.75, 0, 0.4375, 0.0625, 0.875, 0.25, 0.75, 0.625, 0.8125, 0.25, 0.0625, 0.6875, 0.9375, 0.125],
                 [0.6875, 0.875, 1, 0.8125, 0.5625, 0.1875, 0.0625, 1, 0, 0.4375, 0.75, 0.75, 0.1875, 0.625, 1, 0.75, 0.5625, 0.75, 0.75, 0.5625],
                 [0.1875, 0.9375, 1, 0.6875, 0.6875, 0.4375, 0.25, 0.75, 0.75, 0.25, 0.25, 0.875, 0.6875, 0.625, 0.5, 0.8125, 0.0625, 0.6875, 0.6875, 0.1875],
                 [0, 0.25, 1, 0.25, 0, 0, 1, 0.25, 0, 0.125, 1, 0.25, 0.25, 0.9375, 1, 0.25, 0, 0.3125, 0.9375, 0.25],
                 [0.375, 1, 1, 1, 0, 0.8125, 0.5, 0, 0.1875, 0.1875, 0.9375, 0.125, 0.75, 0.625, 0.75, 0.25, 0.0625, 0.75, 0.9375, 0.0625],
                 [0.75, 0.8125, 0.8125, 0.9375, 0.0625, 0.25, 0.3125, 1, 0.25 , 1, 1, 0.375, 0.625, 0.9375, 1, 0.875, 0.125, 0.25, 0.25, 0.1875],
                 [0.5, 0.9375, 1, 0.375, 0.9375, 0.1875, 0.1875, 0.9375, 0.8125, 0, 0, 1, 0.875, 0.375, 0.1875, 0.9375, 0.1875, 0.8125, 1, 0.5],
                 [0.25, 1, 1, 0, 0.25, 1, 1, 0, 0.25, 1, 1, 0, 0.25, 1, 1, 0, 0.25, 1, 1, 0],
                 [0.6875, 1, 1, 1, 0.375, 0.9375, 0.4375, 0, 0.1875, 0.25, 0.8125, 0.375, 0.8125, 0.6875, 0.625, 0.5, 0.0625, 0.5625, 0.75, 0.1875],
                 [0.6875, 0.8125, 0.8125, 0.75, 0.375, 0.125, 0.1875, 1, 0.0625, 0.75, 0.8125, 0.6875, 0.0625, 0.5625, 1, 0.9375, 0.1875, 0.75, 0.75, 0.75],
                 [0.5, 0.875, 0.875, 0.625, 1, 0.125, 0.25, 0.75, 0.75, 0, 0.5, 0.6875, 0.875, 0.25, 0.9375, 0.3125, 0.5625, 0.75, 0.5625, 0],
                 [0.5625, 1, 1, 0.6875, 0, 0, 1, 0, 0.0625, 0.375, 0.875, 0, 0.1875, 0.9375, 0.75, 0, 0, 0.5, 0.5625, 0],
                 [0.6875, 1, 1, 0.875, 0.1875, 0.9375, 0.25, 0.125, 0, 0.1875, 0.9375, 0.125, 0.875, 0.4375, 0.75, 0.25, 0.1875, 0.8125, 0.875, 0.125],
                 [0.8125, 1, 0.9375, 0.5, 0.25, 0.125, 0.5625, 0.75, 0, 0.5625, 1, 0.6875, 0.6875, 0.1875, 0.375, 0.75, 0.375, 1, 0.9375, 0.3125],
                 [0.0625, 0.875, 1, 0.3125, 0.625, 0.6875, 0.3125, 0.75, 0.75, 0.25, 0.25, 0.75, 0.625, 0.625, 0.3125, 0.75, 0.0625, 0.8125, 1, 0.375],
                 [0, 0.75, 1, 0.5, 0, 0.75, 1, 0.5, 0, 0.75, 1, 0.5, 0, 0.75, 1, 0.5, 0, 0.75, 1, 0.5],
                 [0.75, 1, 0.75, 0.8125, 0.0625, 0.8125, 0.625, 0, 0, 0, 0.875, 0.25, 0.5, 0.4375, 1, 0.0625, 0.1875, 0.75, 0.5625, 0],
                 [0.8125, 0.8125, 0.9375, 0.625, 0.25, 0, 0.0625, 1, 0.0625, 0.75, 0.5625, 0.875, 0, 0.4375, 1, 0.8125, 0.5, 0.9375, 0.75, 0.75],
                 [0.375, 0.9375, 0.9375, 0.3125, 1, 0.25, 0.4375, 0.6875, 0.8125, 0.375, 0.25, 0.75, 0.3125, 0.875, 0.8125, 0.625, 0, 0.375, 0.75, 0.3125],
                 [0.1875, 0.9375, 0, 0, 0.1875, 0.9375, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0.625, 0.1875, 0],
                 [0.5, 0.75, 0.75, 0.75, 0.375, 0.875, 0.75, 0.25, 0, 0.0625, 0.9375, 0.125, 0.625, 0.3125, 0.8125, 0.25, 0.1875, 0.875, 0.9375, 0.0625],
                 [0.8125, 1, 0.875, 0.1875, 0.5, 0, 0.4375, 0.9375, 0, 0.625, 0.625, 1, 0.5, 0.6875, 1, 0.6875, 0.4375, 0.5, 0.5, 0.3125],
                 [0.1875, 0.9375, 1, 0.8125, 0.6875, 0.5, 0, 0.875, 0.75, 0.375, 0, 0.875, 0.1875, 0.875, 0.8125, 0.8125, 0, 0.1875, 0.4375, 0.0625],
                 [0, 0, 0.875, 0.625, 0, 0.1875, 1, 0.375, 0, 0.5, 1, 0.125, 0, 0.8125, 0.875, 0, 0.125, 1, 0.625, 0],
                 [0.5, 0.75, 0.75, 0.5625, 0.375, 0.9375, 0.625, 0.125, 0, 0.1875, 1, 0, 0.875, 0.5, 0.9375, 0, 0.1875, 0.75, 0.375, 0],
                 [0.8125, 1, 0.75, 0.1875, 0.75, 0.0625, 0.5625, 0.75, 0, 0.75, 1, 0.5, 0.4375, 0.25, 0.6875, 0.5, 0.375, 0.875, 1, 0.4375],
                 [0.25, 1, 1, 0.625, 0.6875, 0.625, 0.1875, 0.875, 0.6875, 0.4375, 0, 0.75, 0.375, 0.875, 0.125, 0.875, 0, 0.625, 1, 0.75],
                 [0.125, 1, 0, 0, 0, 1, 0, 0, 0, 0.8125, 0.25, 0, 0, 0.75, 0.25, 0, 0, 0.375, 0.125, 0],
                 [0.5, 0.75, 0.6875, 0.5, 0.5625, 0.9375, 0.625, 0.5, 0, 0.5625, 0.875, 0, 0.6875, 0.3125, 1, 0, 0.375, 0.875, 0.9375, 0],
                 [0.1875, 0.6875, 0.75, 0.375, 0.3125, 0.625, 0.625, 0.75, 0, 0.5, 1, 0.9375, 0.5, 0.375, 0.3125, 1, 0.1875, 0.875, 1, 0.75],
                 [0.0625, 0.8125, 1, 0.4375, 0.625, 0.625, 0.375, 0.75, 0.75, 0.3125, 0.25, 0.75, 0.5, 0.8125, 0.6875, 0.625, 0, 0.625, 0.8125, 0.0625],
                 [0, 0.4375, 0.5, 0, 0, 0.5, 0.5, 0, 0, 0.5, 0.5, 0, 0.5, 1, 0.5, 0, 0, 0.5625, 0.4375, 0],
                 [0.875, 0.875, 0.75, 0.875, 0.1875, 0.9375, 0.375, 0, 0, 0.25, 0.9375, 0, 0.5, 0.25, 1, 0, 0.5, 0.875, 0.625, 0],
                 [0.3125, 1, 0.9375, 0.375, 0.1875, 0.3125, 0.25, 0.9375, 0, 0.875, 0.875, 0.875, 0.4375, 0.5, 0.875, 0.3125, 0.3125, 0.75, 0.6875, 0.0625]
])

def sigmoidFunc(totalInput):
    return 1.0 / (np.ones(totalInput.shape)+np.exp(-1.0*totalInput))

def outputDeltas(output, target):
    sigmoidDeriv = output * (np.ones(output.shape)-output)
    return 2 * (target - output) * sigmoidDeriv

def hiddenDeltas(outputDeltas, hiddenOutputs, outputWeights):
    sigmoidDeriv = hiddenOutputs * (np.ones(hiddenOutputs.shape) - hiddenOutputs)
    return (np.dot(outputWeights.T, outputDeltas.T)) * sigmoidDeriv

mList=[0]*1000
tList=[0]*1000
eList=[0]*1000


patterns = data.T
nPats = data.shape[0]
nTrainingPats = 20
nTestPats = 20
nInputs = data.shape[1]
nHidden = 10
nOutputs = 4

hiddenWeights = 0.5 * (np.random.rand(nHidden, nInputs+1)-np.ones((nHidden, nInputs+1))*0.5)
outputWeights = 0.5 * (np.random.rand(nOutputs, nHidden+1)-np.ones((nOutputs, nHidden+1))*0.5)

input = patterns
target = np.zeros((nOutputs, nPats))
classNum = 0
eta = 0.1
NEpochs = 1000
totalNEpochs = 0

minEpochsPerErrorPlot = 200
errorsPerEpoch = np.zeros((1, minEpochsPerErrorPlot))
TestErrorsPerEpoch = np.zeros((1, minEpochsPerErrorPlot))


for pat in range(0, nPats, 1):
    target[classNum, pat] = 1
    classNum = classNum+1
    if classNum >= nOutputs:
        classNum = 0
ErrorsLastNEpochs = np.zeros((1, NEpochs))
TestErrorsLastNEpochs = np.zeros((1, NEpochs))

for epoch in range(0, NEpochs, 1):
    sumSqrError = 0.0
    sumSqrTestError = 0.0
    outputWGrad = np.zeros(outputWeights.shape)
    hiddenWGrad = np.zeros(hiddenWeights.shape)

    for pat in range(0, nTrainingPats, 1):
        inp = np.hstack([input[:, pat], np.array([1])])
        hiddenNetInputs = np.dot(hiddenWeights, inp)
        hiddenStates = sigmoidFunc(hiddenNetInputs)
        hidStatesBias = np.hstack([hiddenStates, np.array([1])])
        outputNetInputs = np.dot(outputWeights, hidStatesBias)
        outputStates = sigmoidFunc(outputNetInputs)

        targetStates = target[:, pat]
        error = outputStates - targetStates
        sumSqrError = sumSqrError + np.dot(error, error)

        outputDel = outputDeltas(outputStates, targetStates)
        outputWGrad = outputWGrad+np.dot(np.array([outputDel]).T, np.array([hidStatesBias]))
        hiddenDel = hiddenDeltas(outputDel, hidStatesBias, outputWeights)
        hiddenDelArray = np.array([hiddenDel])
        hiddenWGrad = hiddenWGrad + np.dot(hiddenDelArray[:, 0:nHidden].T, np.array([inp]))

    outputWChange = eta*outputWGrad
    outputWeights = outputWeights + outputWChange
    hiddenWChange = eta*hiddenWGrad
    hiddenWeights = hiddenWeights + hiddenWChange

    for pat in range(nTrainingPats, nPats, 1):
        inp = np.hstack([input[:, pat], np.array([1])])
        hiddenNetInputs = np.dot(hiddenWeights, inp)
        hiddenStates = sigmoidFunc(hiddenNetInputs)
        hidStatesBias = np.hstack([hiddenStates, np.array([1])])
        outputNetInputs = np.dot(outputWeights, hidStatesBias)
        outputStates = sigmoidFunc(outputNetInputs)

        targetStates = target[:, pat]
        error = outputStates - targetStates
        sumSqrTestError = sumSqrTestError+np.dot(error, error)


    MSE = sumSqrError/nTrainingPats
    TestMSE = sumSqrTestError/nTestPats
    mList[totalNEpochs] = MSE
    tList[totalNEpochs] = TestMSE
    eList[totalNEpochs] = totalNEpochs-1
    totalNEpochs = totalNEpochs + 1
    print('%d MSError = %f, MSTestError=%f'%(totalNEpochs, MSE, TestMSE))

plt.subplot(121)
plt.xlabel('Epochs')
plt.ylabel('MSE')
plt.grid()
plt.plot(eList,mList,'b')
plt.subplot(122)
plt.xlabel('Epochs')
plt.ylabel('TestMSE')
plt.grid()
plt.plot(eList, tList, 'r')
fig = plt.gcf()  # 현재 figure에 불러오기
fig.set_size_inches(14, 14)  # 크기 바꾸기(inch 단위)
plt.show()







