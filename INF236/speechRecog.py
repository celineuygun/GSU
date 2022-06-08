import speech_recognition as sr
from sumapi.api import SumAPI

api = SumAPI(username='GSUINF236', password='RPXfvP2yU7v4')
mic = sr.Microphone()
r = sr.Recognizer()

with sr.Microphone() as source:
    r.adjust_for_ambient_noise(source)
    print("Arka plan gürültüsü:" + str(r.energy_threshold))

    try:
        print("Dinliyorum: ")
        ses = r.listen(source, timeout=2, phrase_time_limit=5)
        print(r.recognize_google(ses, language='tr-tr'))
    except sr.WaitTimeoutError:
        print("Dinleme zaman aşımına uğradı")

    except sr.UnknownValueError:
        print("Ne dediğini anlayamadım")

    except sr.RequestError:
        print("İnternete bağlanamıyorum")

def recognize_speech_from_mic(recognizer, microphone, firsttime = False):
    """Transcribe speech from recorded from `microphone`.

    Returns a dictionary with three keys:
    "success": a boolean indicating whether or not the API request was
               successful
    "error":   `None` if no error occured, otherwise a string containing
               an error message if the API could not be reached or
               speech was unrecognizable
    "transcription": `None` if speech could not be transcribed,
               otherwise a string containing the transcribed text
    """
    # check that recognizer and microphone arguments are appropriate type
    if not isinstance(recognizer, sr.Recognizer):
        raise TypeError("`recognizer` must be `Recognizer` instance")

    if not isinstance(microphone, sr.Microphone):
        raise TypeError("`microphone` must be `Microphone` instance")

    # adjust the recognizer sensitivity to ambient noise and record audio
    # from the microphone
    with microphone as source:
        if firsttime == True:
            recognizer.adjust_for_ambient_noise(source)
        print('recording..')
        audio = recognizer.listen(source)

    # set up the response object
    response = {
        "success": True,
        "error": None,
        "transcription": None
    }

    # try recognizing the speech in the recording
    # if a RequestError or UnknownValueError exception is caught,
    #     update the response object accordingly
    try:
        response["transcription"] = recognizer.recognize_google(audio, language='tr-tr')
    except sr.RequestError:
        # API was unreachable or unresponsive
        response["success"] = False
        response["error"] = "API unavailable"
    except sr.UnknownValueError:
        # speech was unintelligible
        response["error"] = "Unable to recognize speech"

    return response


def cagri():
    guess = recognize_speech_from_mic(r, mic)
    transcription = guess['transcription']
    print(transcription)
    analysis = api.sentiment_analysis(transcription, domain='general')
    return analysis['evaluation']

guess = recognize_speech_from_mic(r, mic, firsttime = True)
print(guess)
api.sentiment_analysis(guess['transcription'], domain='general')
cagri()

print(api.zero_shot_classification('Bu nasıl bir hizmet, gerçekten rezilsiniz.', categories='talep,şikayet,öneri'))
print(api.zero_shot_classification('Mac book pro super bir GPU sahip', categories='teknoloji, spor, ekonomi'))