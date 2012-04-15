# Arduino, Ruby &amp; Sinatra - The Internet Of Things's Rat Pack

Frank, Sammy &amp; Dean were a great team known as the "Rat Pack". What's true for these fellows is also true for Sinatra, Ruby and Arduino: put them together for instant awesomeness!

If you connect the strengths of these three mates, you're able to turn household objects into social objects. Examples range from the amazing talkative ping pong table a.k.a. [Occupy Ping Pong!](https://github.com/makersandco/Occupy-Ping-Pong) Makers & Co. did in cooperation with an Advertising School, over the digital foosball table I prototyped for an agency last year to the [Empathic Servo](https://vimeo.com/27113323) which uses Ruby logic to translate between a face recognition software, the serial port and a servo motor.

To put it short: the Internet of Things is rising and although being a hardware centric concept it still needs some middleware <3 to negotiate. That's where Arduino (Dean), Sinatra (Frank) and Ruby (Sammy) get together for rapid prototyping and instant awesomeness!

## Episode I - The Workshop

This is the workshop we're having [here](http://www.meetup.com/hacktable/events/57399932/). It goes a little like this:

### 1 - Plain Old Button

Use Sven's lovely advices and [this](https://github.com/5v3n/ratpack-theworkshop/zipball/step-1-plainbutton) information to get a Plain Old Button working. It's basically the Arduino button example code plus a hand crafted Fritzing sketch of the wiring that makes a LED light up when we do so.

### 2 - Plain Old Internet Connection

Use Sven's lovely advices and the Arduino Ethernet or [WiFly](https://github.com/timr/WiFly-Shield) library's 'web client' example to get a Plain Old Internet Connection working.

For Arduino 1.0+ that we are using, mind the updated Wifly library version linked above.

### 3 - Sinatra Takes The Stage

We're close to the magic now. [Sinatra](http://www.sinatrarb.com/) is a Ruby library that lets you negotiate between stuff that is online using the verbs of the internet. In more basic terms its a ruby gem offering a domain specific language that enables you to build RESTful web services on top of the ruby middleware rack.

Our stage is [Heroku](http://heroku.com) which is a hosting service where we may let Sinatra perform for free. That is free as in free beer as long as you don't plan to get drunk since it's going to be awful expensive if you order a second one. Just kidding, I <3 heroku and all my apps were or are bootstrapped there.

[...bla bla writing on process...]

Repo revision with the ready server can be found [here](https://github.com/5v3n/ratpack-theworkshop/zipball/step-2-onlinebutton). It uses one Arduino with a Wifly board. To use it with two independent devices (e.g. one on Hamburg, one in Hong Kong) just build another one, they'll interact just nice. Just connect them to the same ratpack server.

### 4 - Ladies &amp; Gentlemen - The RAT PACK!

Here's a roundup of the workflow we just established. We are able to...

- push the button (Arduino)
- tell the server we did so (Arduino - Sinatra)
- tell the server to tell all interesed devices that we did so (Ruby)
- let all interested devices' LEDs light up. globally. (Arduino)
- it's ALIVE!!!! ZOMG!1!!11!! (Hacktable attendees freaking out)

## Episode II - The Talk

coming soon - feel free to vote for the [Euruko 2012 talk proposal](https://github.com/euruko2012/call-for-proposals/pull/60)!